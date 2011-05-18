#ifndef TIMER_H
#define TIMER_H

#include <vector>
#include <set>
#include "IObserverTimer.h"
using namespace std;
namespace Engine
{

struct SObserverTimer
{
    IObserverTimer* observer;
    unsigned int delay;
    unsigned int start;
};

class Timer
{
    public:
        static Timer* getTimer();
        void addListener(IObserverTimer*,int delay);
        void addListenerOnce(IObserverTimer*,int delay);

        void removeListener(IObserverTimer*,int delay);
        void removeListenerOnce(IObserverTimer*,int delay);
        void update();
        virtual ~Timer();
        static unsigned int getTime();
        static unsigned int getTimePerFrame();
    protected:
    private:
        Timer();
        struct SObserverTimer* createSObserverTime(IObserverTimer* observer,int delay);
        static Timer* instance;
        set<struct SObserverTimer*> listener;
        set<struct SObserverTimer*> listenerOnce;
        set<struct SObserverTimer*> listenerRemoved;
        set<struct SObserverTimer*> listenerOnceRemoved;
        static unsigned int last_time;
        static unsigned int ellapsed_time;
};
}

#endif // TIMER_H
