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
        unsigned int getTime();
        unsigned int getTimePerFrame();
        void setTime(unsigned int time);
    protected:
    private:
        Timer();
        struct SObserverTimer* createSObserverTime(IObserverTimer* observer,int delay);
        static Timer* instance;
        set<struct SObserverTimer*> listener;
        set<struct SObserverTimer*> listenerOnce;
        set<struct SObserverTimer*> listenerRemoved;
        set<struct SObserverTimer*> listenerOnceRemoved;
        unsigned int last_time;
        unsigned int ellapsed_time;
        unsigned int delayTime;
};
}

#endif // TIMER_H
