#ifndef IOBSERVERSOCKETRECV_H
#define IOBSERVERSOCKETRECV_H

namespace Engine
{
    class IObserverSocketRecv;
}

#include "Socket.h"

namespace Engine
{
class IObserverSocketRecv
{
    public:
        virtual void updateRecv(Socket *,const char*,int size)=0;
        virtual ~IObserverSocketRecv(){};
    protected:
    private:
};
}

#endif // IOBSERVERSOCKETRECV_H
