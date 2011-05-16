#ifndef IOBSERVERTIMER_H
#define IOBSERVERTIMER_H

namespace Engine
{

class IObserverTimer
{
    public:
        virtual void updateTimer(unsigned int delay)=0;
        virtual ~IObserverTimer() {}
    protected:
    private:
};

}

#endif // IOBSERVERTIMER_H
