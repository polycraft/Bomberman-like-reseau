#include "testEvent.h"


TestEvent::TestEvent()
{

}
virtual ~TestEvent()=0;

/**
Execute les actions suivant les événements
**/
void TestEvent::executeAction(const stateEvent &event);