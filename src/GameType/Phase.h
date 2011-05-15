#ifndef PHASE_H
#define PHASE_H

#include "../CollisionDetector.h"
#include "../Engine/EventEngine/IEventListener.h"

using namespace Engine;

class Phase : public IEventListener
{

public:
	Phase(CollisionDetector *collision);
	virtual ~Phase()=0;
	virtual void init();
	virtual void run();
	virtual void fin( int phase);
	void updateAction();
	void setCollisionDetector(CollisionDetector *collision);

private:
	CollisionDetector *collision;
};



#endif // PHASE_H
