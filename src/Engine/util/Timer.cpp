#include "Timer.h"
#include <SDL/SDL.h>
#include <iostream>
using namespace std;
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
{cout << "addListener" << endl;
    struct SObserverTimer* sObserver=createSObserverTime(observer,delay);

    listener.insert(sObserver);
}

void Timer::addListenerOnce(IObserverTimer* observer,int delay)
{cout << "addListenerOnce" << endl;
    struct SObserverTimer* sObserver=createSObserverTime(observer,delay);

    listenerOnce.insert(sObserver);
}

void Timer::removeListener(IObserverTimer*observer,int delay)
{
    struct SObserverTimer* sObserver=createSObserverTime(observer,delay);
    listenerRemoved.insert(sObserver);

    /*set< struct SObserverTimer* >::iterator it;
    struct SObserverTimer* sObserver=NULL;

	for(it=this->listener.begin(); it!=listener.end();)
	{
		sObserver=*it;

		if(sObserver->observer==observer && sObserver->delay==delay)
        {
            listener.erase(it++);
            return;
        }
		it++;
	}*/

	/*
    while(it<listener.end())
    {
        sObserver=*it;

        if(sObserver->observer==observer && sObserver->delay==delay)
        {
            it=listener.erase(it);
            return;
        }
        it++;
    }*/
}

void Timer::removeListenerOnce(IObserverTimer*observer,int delay)
{
    struct SObserverTimer* sObserver=createSObserverTime(observer,delay);
    listenerOnceRemoved.insert(sObserver);

    /*set< struct SObserverTimer* >::iterator it;
    struct SObserverTimer* sObserver=NULL;

	for(it=this->listenerOnce.begin(); it!=listenerOnce.end();)
	{
		sObserver=*it;

		if(sObserver->observer==observer && sObserver->delay==delay)
        {
            listenerOnce.erase(it++);
            return;
        }
		it++;
	}*/

    /*while(it<listenerOnce.end())
    {
        sObserver=*it;

        if(sObserver->observer==observer && sObserver->delay==delay)
        {
            it=listenerOnce.erase(it);
            return;
        }
        it++;
    }*/
}

void Timer::update()
{
    //On verifie les listeners
    set< struct SObserverTimer* >::iterator it;
    struct SObserverTimer* sObserver=NULL;



	for(it=this->listener.begin(); it!=listener.end();)
	{
		sObserver=*it;

		if(sObserver->start+sObserver->delay <= SDL_GetTicks())
        {
            sObserver->observer->updateTimer(sObserver->delay);
            sObserver->start=SDL_GetTicks();
        }
		it++;
	}

    /*while(it<listener.end())
    {
        sObserver=*it;

        if(sObserver->start+sObserver->delay <= SDL_GetTicks())
        {
            sObserver->observer->updateTimer(sObserver->delay);
            sObserver->start=SDL_GetTicks();
        }
        it++;
    }*/

    //On vérifie les listeners qui doivent etre appellé qu'une seul fois
	int test = listenerOnce.size();

	for(it=this->listenerOnce.begin(); it!=listenerOnce.end();)
	{
		sObserver=*it;

		if(sObserver->start+sObserver->delay <= SDL_GetTicks())
        {
            sObserver->observer->updateTimer(sObserver->delay);
            listenerOnce.erase(it++);
        }
		 else
        {
            it++;
        }
	}

	/* it=listenerOnce.begin();
    while(it!=listenerOnce.end())
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
    }*/

    //Suppresion des timers
    set< struct SObserverTimer* >::iterator itDelete;
    for(it=this->listenerRemoved.begin(); it!=listenerRemoved.end();)
	{

		for(itDelete=this->listener.begin(); itDelete!=listener.end();)
		{
            sObserver=*itDelete;
		    if(sObserver->observer==(*it)->observer && sObserver->delay==(*it)->delay)
		    {
		        listener.erase(itDelete);
		        break;
		    }
		    itDelete++;
		}
		it++;
	}
	listenerRemoved.clear();

    for(it=this->listenerOnceRemoved.begin(); it!=listenerOnceRemoved.end();)
	{
		for(itDelete=this->listenerOnce.begin(); itDelete!=listenerOnce.end();)
		{
		    sObserver=*itDelete;
		    if(sObserver->observer==(*it)->observer && sObserver->delay==(*it)->delay)
		    {
		        listenerOnce.erase(itDelete);
		        break;
		    }
		    itDelete++;
		}
		it++;
	}
	listenerOnceRemoved.clear();

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
