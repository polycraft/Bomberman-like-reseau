#ifndef IOBSERVERSOCKETACCEPT_H
#define IOBSERVERSOCKETACCEPT_H

namespace Engine
{
    class IObserverSocketAccept;
}
#include "Socket.h"

namespace Engine
{
class IObserverSocketAccept
{
    public:
        virtual void updateAccept(Socket*)=0;
        virtual ~IObserverSocketAccept(){};
    protected:
    private:
};
}

#endif // IOBSERVERSOCKETACCEPT_H
