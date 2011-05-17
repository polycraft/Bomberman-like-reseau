#include "Timer.h"
#include <SDL/SDL.h>

namespace Engine
{
    Timer* Timer::instance=NULL;
    unsigned int Timer::last_time=Timer::getTime();
    unsigned int Timer::ellapsed_time=0;

Timer *Timer::getTimer()
{
    if(instance==NULL)
    {
        instance=new Timer();
    }
    return instance;
}

Timer::Timer()
{

}

Timer::~Timer()
{

}

struct SObserverTimer* Timer::createSObserverTime(IObserverTimer* observer,int delay)
{
    struct SObserverTimer* sObserver=new struct SObserverTimer;
    sObserver->start=SDL_GetTicks();
    sObserver->observer=observer;
    sObserver->delay=delay;

    return sObserver;
}

void Timer::addListener(IObserverTimer* observer,int delay)
{
    struct SObserverTimer* sObserver=createSObserverTime(observer,delay);

    listener.push_back(sObserver);
}

void Timer::addListenerOnce(IObserverTimer* observer,int delay)
{
    struct SObserverTimer* sObserver=createSObserverTime(observer,delay);

    listenerOnce.push_back(sObserver);
}

void Timer::removeListener(IObserverTimer*observer,int delay)
{
    vector< struct SObserverTimer* >::iterator it=listener.begin();
    struct SObserverTimer* sObserver=NULL;

    while(it<listener.end())
    {
        sObserver=*it;

        if(sObserver->observer==observer && sObserver->delay==delay)
        {
            it=listener.erase(it);
            return;
        }
        it++;
    }
}

void Timer::removeListenerOnce(IObserverTimer*observer,int delay)
{
    vector< struct SObserverTimer* >::iterator it=listenerOnce.begin();
    struct SObserverTimer* sObserver=NULL;

    while(it<listenerOnce.end())
    {
        sObserver=*it;

        if(sObserver->observer==observer && sObserver->delay==delay)
        {
            it=listenerOnce.erase(it);
            return;
        }
        it++;
    }
}

void Timer::update()
{
    //On verifie les listeners
    vector< struct SObserverTimer* >::iterator it=listener.begin();
    struct SObserverTimer* sObserver=NULL;

    while(it<listener.end())
    {
        sObserver=*it;

        if(sObserver->start+sObserver->delay <= SDL_GetTicks())
        {
            sObserver->observer->updateTimer(sObserver->delay);
            sObserver->start=SDL_GetTicks();
        }
        it++;
    }

    //On vérifie les listeners qui doivent etre appellé qu'une seul fois
    it=listenerOnce.begin();
    while(it<listenerOnce.end())
    {
        sObserver=*it;
        if(sObserver->start+sObserver->delay <= SDL_GetTicks())
        {
            sObserver->observer->updateTimer(sObserver->delay);
            it=listenerOnce.erase(it);
        }
        else
        {
            it++;
        }
    }

    //Mise à jours du temps passé
    int tmp=Timer::getTime();
    ellapsed_time=tmp-last_time;
    last_time=tmp;

    if(ellapsed_time<8)
    {
        SDL_Delay(8-ellapsed_time);
        ellapsed_time=8;
    }
}

unsigned int Timer::getTime()
{
    return SDL_GetTicks();
}

unsigned int Timer::getTimePerFrame()
{
    return ellapsed_time;
}


}
