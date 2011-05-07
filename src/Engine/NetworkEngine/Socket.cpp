#include "Socket.h"
#include <stdlib.h>

#include "../Exception/Exception.h"

namespace Engine
{
Socket::Socket(char *address,unsigned int port,ETypeProtocole protocole,ETypeConnection connection)
{
#ifdef WINDOWS
    Socket::init();
#endif

    this->connection=connection;
    this->protocole=protocole;

    infoConnection= {0};

    switch(protocole)
    {
    case TCP:
        this->sock=socket(AF_INET, SOCK_STREAM, 0);
        break;
    case UDP:
        this->sock=socket(AF_INET, SOCK_DGRAM, 0);
        break;
    }


    if(sock == INVALID_SOCKET)
    {
        throw ExceptionInvalidSocket();
    }

    infoConnection.sin_port = htons(port);
    infoConnection.sin_family = AF_INET;

    switch(connection)
    {
    case Server:
        infoConnection.sin_addr.s_addr = htonl(INADDR_ANY);

        if(bind(sock,(SOCKADDR *) &infoConnection, sizeof infoConnection) == SOCKET_ERROR)
        {
            throw ExceptionListen();
        }

        if(protocole==TCP)
        {
            if(listen(sock, 20) == SOCKET_ERROR)
            {
                throw ExceptionListen();
            }
        }
        break;
    case Client:
        struct hostent *hostinfo;
        hostinfo = gethostbyname(address);

        if (hostinfo == NULL)
        {
            throw ExceptionUnknowHost();
        }

        infoConnection.sin_addr = *(IN_ADDR *) hostinfo->h_addr;

        if(connect(sock,(SOCKADDR *) &infoConnection, sizeof(SOCKADDR)) == SOCKET_ERROR)
        {
            throw ExceptionConnect();
        }
        break;
    }

    this->isConnect=true;


    this->sizeBufferSend=1024;
    this->sizeBufferRecv=1024;
    this->bufferRecv=(char*)malloc(sizeof(char)*this->sizeBufferRecv);
    this->bufferSend=(char*)malloc(sizeof(char)*this->sizeBufferSend);

    this->observerRecv=vector<IObserverSocketRecv*>(10);
    this->observerAccept=vector<IObserverSocketAccept*>(10);
}

Socket::Socket(SOCKET sock,ETypeConnection connection)
{
    this->sock=sock;
    this->connection=connection;
    this->protocole=TCP;

    this->isConnect=true;


    this->sizeBufferSend=1024;
    this->sizeBufferRecv=1024;
    this->bufferRecv=(char*)malloc(sizeof(char)*this->sizeBufferRecv);
    this->bufferSend=(char*)malloc(sizeof(char)*this->sizeBufferSend);

    this->observerRecv=vector<IObserverSocketRecv*>(10);
    this->observerAccept=vector<IObserverSocketAccept*>(10);
}

Socket::~Socket()
{
    closesocket(sock);

#ifdef WINDOWS
    Socket::end();
#endif
}

void Socket::runThread(bool *close)
{
    fd_set rdfs;

    while(*close!=true)
    {
        FD_ZERO(&rdfs);
        FD_SET(sock, &rdfs);

        if(select(sock + 1, &rdfs, NULL, NULL, NULL) == -1)
        {
            throw ExceptionSelect();
        }

        //un paquet est arrivé
        if(FD_ISSET(sock, &rdfs))
        {
            //Nouvelle connexion
            if(this->connection==Server && this->protocole==TCP)
            {
                SOCKADDR_IN csin = { 0 };
                size_t sinsize = sizeof csin;
                SOCKET csock = accept(sock, (SOCKADDR *)&csin, &sinsize);

                if(csock == SOCKET_ERROR)
                {
                    continue;
                }
                notifyAccept(new Socket(csock,Client));
            }
            else
            {
                this->recvData();
            }
        }
    }
}

bool Socket::hasConnect()
{
    return isConnect;
}

unsigned int Socket::getSizeBufferRecv()
{
    return this->sizeBufferRecv;
}

void Socket::setSizeBufferRecv(unsigned int val)
{
    this->sizeBufferRecv=val;
    this->bufferRecv=(char*)realloc(this->bufferRecv,sizeof(char)*val);
}

unsigned int Socket::getSizeBufferSend()
{
    return this->sizeBufferSend;
}

void Socket::setSizeBufferSend(unsigned int val)
{
    this->sizeBufferSend=val;
    this->bufferSend=(char*)realloc(this->bufferSend,sizeof(char)*val);
}

void Socket::sendData(const char *data,unsigned int size)
{
    if(protocole==TCP)
    {
        if(send(sock, data, size, 0) < 0)
        {
            throw ExceptionSend();
        }
    }
    else if(protocole==UDP)
    {
        //à faire si necessaire
    }
}
void Socket::sendData(string &data)
{
    return this->sendData(data.c_str(),data.size());
}

void Socket::recvData()
{
    if(protocole==TCP)
    {
        int n = 0;

        if((n = recv(sock, bufferRecv, sizeBufferRecv - 1, 0)) < 0)
        {
            throw ExceptionRecv();
        }

        bufferRecv[n] = 0;

        this->notifyRecv(bufferRecv);
    }
    else if(protocole==UDP)
    {
        //à faire si necessaire
    }
}

void Socket::addObserverRecv(IObserverSocketRecv* observer)
{
    this->observerRecv.push_back(observer);
}

void Socket::addObserverAccept(IObserverSocketAccept* observer)
{
    this->observerAccept.push_back(observer);
}

void Socket::notifyRecv(char* s)
{
    for (vector<IObserverSocketRecv*>::iterator it = observerRecv.begin(); it!=observerRecv.end(); ++it)
    {
        (*it)->update(s);
    }
}

void Socket::notifyAccept(Socket *s)
{
    for (vector<IObserverSocketAccept*>::iterator it = observerAccept.begin(); it!=observerAccept.end(); ++it)
    {
        (*it)->update(s);
    }
}

#ifdef WINDOWS
unsigned int Socket::nbSocket = 0;
bool Socket::isInit = false;

static void Socket::init()
{
    Socket::nbSocket++;
    if(!Socket::isInit)
    {
        WSADATA wsa;
        int err = WSAStartup(MAKEWORD(2, 2), &wsa);
        if(err < 0)
        {
            throw ExceptionInitSocket;
        }
    }
}

static void end()
{
    Socket::nbSocket--;
    if(Socket::isInit && nbSocket==0)
    {
        WSACleanup();
        Socket::isInit=false;
    }
}

#endif

}
