#ifndef HURRYUP_H
#define HURRYUP_H

#include "../Phase.h"


class HurryUp : public Phase
{

public:
	HurryUp(CollisionDetector collision);
	virtual ~HurryUp();
	void run();
	void updateTimer();
	
private:

};



#endif // HURRYUP_H