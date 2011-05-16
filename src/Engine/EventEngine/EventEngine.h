#ifndef EVENTENGINE_H
#define EVENTENGINE_H

#include <vector>
#include <map>
#include <SDL/SDL.h>

#include "IEventListener.h"

using namespace std;

namespace Engine
{
    class EventEngine
    {
        public:
            EventEngine();
            virtual ~EventEngine();

            /**
            Met à jours les evenements
            **/
            bool update();

            /**
            Appel les écouteurs d'evenements
            **/
            void callListener();

            /**
            Ajoute un écouteur
            **/
            void addListener(IEventListener *listener);

            /**
            Retire un écouteur
            **/
            void removeListener(IEventListener *listener);
        private:
            /**
            Tableau des écouteurs
            **/
            vector<IEventListener*> listener;

            /**
            Status des événements
            **/
            stateEvent event;
    };
}
#endif // EVENTENGINE_H
