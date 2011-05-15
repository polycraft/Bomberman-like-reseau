#ifndef PHASE_H
#define PHASE_H

#include "../CollisionDetector.h"
#include "../Engine/EventEngine/IEventListener.h"

using namespace Engine;

class Phase : public IEventListener
{

public:
	Phase(CollisionDetector *collision);
	virtual ~Phase(){};
	virtual void init()=0;
	virtual void run()=0;
	virtual void end( int phase);
	virtual void updateAction()=0;
	void setCollisionDetector(CollisionDetector *collision);

private:
	CollisionDetector *collision;
};



#endif // PHASE_H
