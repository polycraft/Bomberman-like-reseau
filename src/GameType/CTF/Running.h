#ifndef RUNNING_H
#define RUNNING_H

#include "../Phase.h"


class Running : public Phase
{

public:
	Running(CollisionDetector *collision);
	virtual ~Running();
	void init();
	void run();
	void updateTimer();

private:

};



#endif // RUNNING_H