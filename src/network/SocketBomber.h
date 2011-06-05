#ifndef SOCKETBOMBER_H
#define SOCKETBOMBER_H

#include "../Engine/NetworkEngine/Socket.h"
#include <queue>

class SocketBomber: public Engine::Socket
{
    public:
        SocketBomber(const char *address,unsigned int port,Engine::ETypeProtocole protocole=Engine::TP_TCP,Engine::ETypeConnection connection=Engine::TC_Client);
        SocketBomber(unsigned int port,Engine::ETypeProtocole protocole);
        virtual ~SocketBomber();
        virtual Engine::Paquet recvData();
    protected:
    private:
        std::queue<Engine::Paquet> waiting;
};

#endif // SOCKETBOMBER_H
