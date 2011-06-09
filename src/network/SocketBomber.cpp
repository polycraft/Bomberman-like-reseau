#include "SocketBomber.h"
#include "../Type/Paquet.h"

using namespace Engine;

SocketBomber::SocketBomber(const char *address,unsigned int port,ETypeProtocole protocole,ETypeConnection connection):
    Socket(address,port,protocole,connection)
{

}
SocketBomber::SocketBomber(unsigned int port,ETypeProtocole protocole):
    Socket(port,protocole)
{

}

SocketBomber::SocketBomber(SOCKET sock,SOCKADDR_IN csin,ETypeConnection connection):
    Socket(sock,csin,connection)
{

}

SocketBomber::~SocketBomber()
{
    //dtor
}

Socket* SocketBomber::createSocketAccept(SOCKET sock,SOCKADDR_IN csin,ETypeConnection connection)
{
    return new SocketBomber(sock,csin,connection);
}

void SocketBomber::recvData()
{
    annalysePaquet();

    this->notifyRecv(waiting.front());
}

Engine::Paquet SocketBomber::recvDataSync()
{
    annalysePaquet();
    return waiting.front();
}

void SocketBomber::annalysePaquet()
{
        if(waiting.size()>0)
    {
        waiting.pop();
    }
    //Paquet en attente
    if(waiting.size()==0)
    {
        if(protocole==TP_TCP)
        {
            int n = recept();

            if(n>0)
            {
                int i=0;
                int size=0;

                while(i<n)
                {
                    char type=bufferRecv[i];

                    switch(type)
                    {
                    case 'b':
                        size=sizeof(PaquetBomb);
                        break;
                    case 'm':
                        size=sizeof(PaquetMove);
                        break;
                    case 'u':
                        size=sizeof(PaquetBonus);
                        break;
                    case 'p':
                        size=sizeof(PaquetPhase);
                        break;
                    case 'e':
                        size=sizeof(PaquetEtat);
                        break;
                    case 'i':
                        size=sizeof(PaquetId);
                        break;
                    case 's':
                        size=sizeof(PaquetSpawn);
                        break;
                    case 'c':
                        size=sizeof(PaquetMap);
                        break;
                    case 'g':
                        size=sizeof(PaquetPing);
                        break;
                    case 'a':
                        size=sizeof(PaquetAsk);
                        break;
                    case 'r':
                        size=sizeof(PaquetError);
                        break;
                    case 'd':
                        size=sizeof(PaquetDeconnect);
                        break;
                    case 'n':
                        size=sizeof(PaquetName);
                        break;
                    case 'f':
                        size=sizeof(PaquetEffect);
                        break;
                    case 'h':
                        size=sizeof(PaquetHurry);
                        break;
                    default:
                        throw ExceptionRecv();
                        break;
                    }
                    waiting.push(Paquet(&(bufferRecv[i]),size));
                    i+=size;
                }
            }
        }
        else if(protocole==TP_UDP)
        {
            //à faire si necessaire
        }
    }
}


