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
        virtual void update(Socket*)=0;
        virtual ~IObserverSocketAccept()=0;
    protected:
    private:
};
}

#endif // IOBSERVERSOCKETACCEPT_H
