#include "Socket.h"
#include <stdlib.h>

#include "../Exception/Exception.h"
#include <iostream>

namespace Engine
{
Socket::Socket(const char *address,unsigned int port,ETypeProtocole protocole,ETypeConnection connection)
{
    initSocket(address,port,protocole,connection);

    initMutex(mutex1);
}

Socket::Socket(unsigned int port,ETypeProtocole protocole)
{
    initSocket(NULL,port,protocole,TC_Server);

    initMutex(mutex1);
}

Socket::Socket(SOCKET sock,SOCKADDR_IN csin,ETypeConnection connection)
{
    this->sock=sock;
    this->connection=connection;
    this->protocole=TP_TCP;
    this->infoConnection=csin;

    this->isConnect=true;

    initBuffer();

    initMutex(mutex1);
}

void Socket::initSocket(const char *address,unsigned int port,ETypeProtocole protocole,ETypeConnection connection)
{
#ifdef WINDOWS
    Socket::init();
#endif

    this->connection=connection;
    this->protocole=protocole;

    //infoConnection= {0};

    switch(protocole)
    {
    case TP_TCP:
        this->sock=socket(AF_INET, SOCK_STREAM, 0);
        break;
    case TP_UDP:
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
    case TC_Server:
        infoConnection.sin_addr.s_addr = htonl(INADDR_ANY);

        if(bind(sock,(SOCKADDR *) &infoConnection, sizeof infoConnection) == SOCKET_ERROR)
        {
            throw ExceptionListen();
        }

        if(protocole==TP_TCP)
        {
            if(listen(sock, 20) == SOCKET_ERROR)
            {
                throw ExceptionListen();
            }
        }
        break;
    case TC_Client:
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
    initBuffer();
}

void Socket::initBuffer()
{
    this->sizeBufferSend=1024;
    this->sizeBufferRecv=1024;
    this->bufferRecv=(char*)malloc(sizeof(char)*this->sizeBufferRecv);
    this->bufferSend=(char*)malloc(sizeof(char)*this->sizeBufferSend);

    this->observerRecv=vector<IObserverSocketRecv*>();
    this->observerAccept=vector<IObserverSocketAccept*>();
}

Socket::~Socket()
{
    stop();
    closesocket(sock);

    sock=-1;

    stopMutex(mutex1);

P();
    free(this->bufferRecv);
    free(this->bufferSend);
    this->bufferSend=NULL;
    this->bufferRecv=NULL;
V();

#ifdef WINDOWS
    Socket::end();
#endif
}

void Socket::runThread(bool *close)
{
    fd_set rdfs;
    struct timeval tv;



    while(*close!=true && sock!=-1)
    {
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        FD_ZERO(&rdfs);
        FD_SET(sock, &rdfs);

        if(select(sock + 1, &rdfs, NULL, NULL, &tv) == -1)
        {
            throw ExceptionSelect();
        }

        //un paquet est arrivé
        if(FD_ISSET(sock, &rdfs) && !isSync)
        {
            //Nouvelle connexion
            if(this->connection==TC_Server && this->protocole==TP_TCP)
            {
                SOCKADDR_IN csin = { 0 };
                socklen_t sinsize = sizeof csin;
                SOCKET csock = accept(sock, (SOCKADDR *)&csin, &sinsize);

                if(csock == SOCKET_ERROR)
                {
                    continue;
                }
                notifyAccept(new Socket(csock,csin,TC_Client));
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
    if(protocole==TP_TCP)
    {
        P();
        if(send(sock, data, size, 0) < 0)
        {
            V();
            throw ExceptionSend();
        }
        V();
    }
    else if(protocole==TP_UDP)
    {
        //à faire si necessaire
    }
}
void Socket::sendData(string &data)
{
    return this->sendData(data.c_str(),data.size());
}

void Socket::sendData(Paquet &paquet)
{
    return this->sendData(paquet.getData(),paquet.getSize());
}

Paquet Socket::recvData()
{
    if(protocole==TP_TCP)
    {
        int n = 0;

        P();
        if((n = recv(sock, bufferRecv, sizeBufferRecv - 1, 0)) < 0)
        {
            V();
            throw ExceptionRecv();
        }
        V();
        if(this->isSync)
        {
            return Paquet(bufferRecv,n);
        }
        else
        {
            this->notifyRecv(bufferRecv,n);
        }
    }
    else if(protocole==TP_UDP)
    {
        //à faire si necessaire
    }
}

void Socket::setIsSync(bool sync)
{
    this->isSync=sync;
}

void Socket::addObserverRecv(IObserverSocketRecv* observer)
{
    this->observerRecv.push_back(observer);
}

void Socket::addObserverAccept(IObserverSocketAccept* observer)
{
    this->observerAccept.push_back(observer);
}

void Socket::removeObserverRecv(IObserverSocketRecv* observer)
{
    for (vector<IObserverSocketRecv*>::iterator it = observerRecv.begin(); it!=observerRecv.end(); ++it)
    {
        if(*it==observer)
        {
            observerRecvSupr.push_back(it);
            break;
        }
    }
}

void Socket::removeObserverAccept(IObserverSocketAccept* observer)
{
    for (vector<IObserverSocketAccept*>::iterator it = observerAccept.begin(); it!=observerAccept.end(); ++it)
    {
        if(*it==observer)
        {
            observerAccept.erase(it);
            break;
        }
    }
}

void Socket::notifyRecv(char* s,int size)
{
    P(mutex1);

    Paquet paquet(s,size);
    for (vector<IObserverSocketRecv*>::iterator it = observerRecv.begin(); it!=observerRecv.end(); ++it)
    {
        //std::cout << observerRecv.size() <<std::endl;
        if(*it!=NULL)
        {
            (*it)->updateRecv(this,paquet);
        }
    }

    vector<vector<IObserverSocketRecv*>::iterator>::iterator it = observerRecvSupr.begin();
    while(observerRecvSupr.size()!=0)
    {
        it=observerRecvSupr.begin();
        observerRecvSupr.erase(it);
    }
    V(mutex1);
}

void Socket::notifyAccept(Socket *s)
{
    for (vector<IObserverSocketAccept*>::iterator it = observerAccept.begin(); it!=observerAccept.end(); ++it)
    {
        if(*it!=NULL)
        {
            (*it)->updateAccept(s);
        }
    }
}

#ifdef WINDOWS
unsigned int Socket::nbSocket = 0;
bool Socket::isInit = false;

void Socket::init()
{
    Socket::nbSocket++;
    if(!Socket::isInit)
    {
        WSADATA wsa;
        int err = WSAStartup(MAKEWORD(2, 2), &wsa);
        if(err < 0)
        {
            throw ExceptionInitSocket();
        }
    }
}

void Socket::end()
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

