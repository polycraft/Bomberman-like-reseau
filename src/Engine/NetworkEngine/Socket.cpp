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
	this->isSync = false;

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
	this->isSync = false;
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

    this->observerRecv=set<IObserverSocketRecv*>();
    this->observerAccept=set<IObserverSocketAccept*>();
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
    observerAccept.clear();
    observerRecv.clear();
    observerRecvSupr.clear();

#ifdef WINDOWS
    Socket::end();
#endif
}

void Socket::runThread(bool *close)
{
    this->closeThread=close;
    while(*close!=true && sock!=-1)
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
            notifyAccept(createSocketAccept(csock,csin,TC_Client));
        }
        else if(!isSync)
        {
			this->recvData();
        }
    }
}

Socket* Socket::createSocketAccept(SOCKET sock,SOCKADDR_IN csin,ETypeConnection connection)
{
    return new Socket(sock,csin,connection);
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

int Socket::recept()
{
    int n=recv(sock, bufferRecv, sizeBufferRecv - 1, 0);

    //Erreur
    if(n<0)
    {
        notifyDisconnect();
        throw ExceptionRecv();
    }
    //Deconnexion
    else if(n==0)
    {
        this->notifyDisconnect();
    }
    return n;
}

Paquet Socket::recvDataSync()
{
    if(protocole==TP_TCP)
    {
        int n = recept();

        if(n>0 && this->isSync)
        {
            return Paquet(bufferRecv,n);
        }
    }
    else if(protocole==TP_UDP)
    {
        //à faire si necessaire
    }
}

void Socket::recvData()
{
    if(protocole==TP_TCP)
    {
        int n = recept();

        if(n>0 && !this->isSync)
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
    this->observerRecv.insert(observer);
}

void Socket::addObserverAccept(IObserverSocketAccept* observer)
{
    this->observerAccept.insert(observer);
}

void Socket::removeObserverRecv(IObserverSocketRecv* observer)
{
    observerRecvSupr.insert(observer);
}

void Socket::removeObserverAccept(IObserverSocketAccept* observer)
{
    observerAccept.erase(observer);
}

void Socket::notifyRecv(char* s,int size)
{
    this->notifyRecv(Paquet(s,size));
}

void Socket::notifyRecv(Paquet paquet)
{
    P(mutex1);

    for (set<IObserverSocketRecv*>::iterator it = observerRecv.begin(); it!=observerRecv.end(); ++it)
    {
        (*it)->updateRecv(this,paquet);
    }

    for (set<IObserverSocketRecv*>::iterator it = observerRecvSupr.begin(); it!=observerRecvSupr.end(); ++it)
    {
        observerRecv.erase(*it);
    }
    observerRecvSupr.clear();
    V(mutex1);
}

void Socket::notifyDisconnect()
{
    P(mutex1);
    *closeThread=true;
    bool deleted=false;

    set<IObserverSocketRecv*>::iterator itDelete = observerRecvSupr.begin();

    for (set<IObserverSocketRecv*>::iterator it = observerRecv.begin(); it!=observerRecv.end(); ++it)
    {
        //On vérifie que l'object n'ai pas été supprimé
        for (itDelete = observerRecvSupr.begin(); itDelete!=observerRecvSupr.end(); ++itDelete)
        {
            if(*it==*itDelete)
            {
                deleted=true;
                break;
            }
        }

        //Si pas supprimé
        if(!deleted)
        {
            (*it)->updateDisconnect(this);
        }
    }

    observerRecvSupr.clear();
    observerRecv.clear();

    V(mutex1);
}

void Socket::notifyAccept(Socket *s)
{
    for (set<IObserverSocketAccept*>::iterator it = observerAccept.begin(); it!=observerAccept.end(); ++it)
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

