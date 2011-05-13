#ifndef TIMER_H
#define TIMER_H

#include <vector>
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
        void update();
        virtual ~Timer();
    protected:
    private:
        Timer();
        struct SObserverTimer* createSObserverTime(IObserverTimer* observer,int delay);
        static Timer* instance;
        vector<struct SObserverTimer*> listener;
        vector<struct SObserverTimer*> listenerOnce;
};
}

#endif // TIMER_H
