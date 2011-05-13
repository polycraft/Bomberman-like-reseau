#ifndef IEVENTLISTENER_H
#define IEVENTLISTENER_H

#include <map>
#include <SDL/SDL.h>

namespace Engine
{
    typedef struct
    {
        std::map<SDLKey,bool> keyState;
        SDL_Event event;
    } stateEvent;

    /**
    Interface des écouteurs
    **/
    class IEventListener
    {
        public:
            IEventListener(){};
            virtual ~IEventListener()=0;

            /**
            Execute les actions suivant les événements
            **/
            virtual void executeAction(const stateEvent &event)=0;
        protected:
        private:
    };
}

#endif // IEVENTLISTENER_H
