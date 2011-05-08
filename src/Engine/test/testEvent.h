#ifndef TESTEVENT_H
#define TESTEVENT_H
#include "../EventEngine/IEventListener.h"

namespace Engine
{
    class TestEvent : public IEventListener
    {
        public:
            TestEvent();
            ~TestEvent();

            /**
            Execute les actions suivant les événements
            **/
            void executeAction(const stateEvent &event);
        protected:
        private:
    };
}

#endif // TESTEVENT_H
