#ifndef SOCKETBOMBER_H
#define SOCKETBOMBER_H

#include "../Engine/NetworkEngine/Socket.h"
#include <queue>

class SocketBomber: public Engine::Socket
{
    public:
        SocketBomber(const char *address,unsigned int port,Engine::ETypeProtocole protocole=Engine::TP_TCP,Engine::ETypeConnection connection=Engine::TC_Client);
        SocketBomber(unsigned int port,Engine::ETypeProtocole protocole);
        SocketBomber(SOCKET sock,SOCKADDR_IN csin,Engine::ETypeConnection connection);
        virtual ~SocketBomber();

        virtual Engine::Socket* createSocketAccept(SOCKET sock,SOCKADDR_IN csin,Engine::ETypeConnection connection);
        virtual void recvData();
        virtual Engine::Paquet recvDataSync();
    protected:
    private:
        void annalysePaquet();
        std::queue<Engine::Paquet> waiting;
};

#endif // SOCKETBOMBER_H
