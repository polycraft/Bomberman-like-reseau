#ifndef IOBSERVERSOCKETRECV_H
#define IOBSERVERSOCKETRECV_H

namespace Engine
{
    class IObserverSocketRecv;
}

#include "Socket.h"
#include "Paquet.h"

namespace Engine
{
class IObserverSocketRecv
{
    public:
        virtual void updateRecv(Socket *,Paquet &)=0;
        virtual void updateDisconnect(Socket* socket){};
        virtual ~IObserverSocketRecv(){};
    protected:
    private:
};
}

#endif // IOBSERVERSOCKETRECV_H
