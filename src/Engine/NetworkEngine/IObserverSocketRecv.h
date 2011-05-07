#ifndef IOBSERVERSOCKETRECV_H
#define IOBSERVERSOCKETRECV_H

namespace Engine
{
class IObserverSocketRecv
{
    public:
        virtual void update(char*)=0;
        virtual ~IObserverSocketRecv()=0;
    protected:
    private:
};
}

#endif // IOBSERVERSOCKETRECV_H
