#include <vector>

#include "EventEngine.h"

using namespace std;

namespace Engine
{
    EventEngine::EventEngine()
    {

    }

    EventEngine::~EventEngine()
    {
        //Todo libérer les listeners
        //delete listener;
    }

    bool EventEngine::update()
    {
        while ( SDL_PollEvent(&(event.event) )) {
            if(event.event.type==SDL_QUIT)
            {
                return false;
            }
            switch(event.event.type)
            {
                case SDL_KEYDOWN:
                     event.keyState[event.event.key.keysym.sym]=true;
                break;
                case SDL_KEYUP:
                    event.keyState[event.event.key.keysym.sym]=false;
                break;
            }
        }

            callListener();

        return true;
    }

    void EventEngine::callListener()
    {
        vector<IEventListener*>::iterator it;

        for ( it=listener.begin() ; it < listener.end(); it++ )
        {
            (*it)->executeAction(event);
        }
    }

    void EventEngine::addListener(IEventListener *listener)
    {
        this->listener.push_back(listener);
    }

    void EventEngine::removeListener(IEventListener *listener)
    {
        vector<IEventListener*>::iterator it;

        for ( it=this->listener.begin() ; it < this->listener.end(); it++ )
        {
            if(listener==*it)
            {
                this->listener.erase(it);
                return;
            }
        }
    }
}
