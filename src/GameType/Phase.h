#ifndef PHASE_H
#define PHASE_H

#include "../CollisionDetector.h"
#include "../Engine/EventEngine/IEventListener.h"

class Phase : public IEventListener
{

public:
	Phase(CollisionDetector *collision);
	virtual ~Phase();
	virtual void init();
	virtual void run();
	virtual void fin( int phase);
	void updateAction();
	void setCollisionDetector(CollisionDetector *collision);

private:
	CollisionDetector *collision;
};



#endif // PHASE_H
