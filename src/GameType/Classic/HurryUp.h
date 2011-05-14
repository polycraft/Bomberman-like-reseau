#ifndef HURRYUP_H
#define HURRYUP_H

#include "../Phase.h"
#include "Running.h"

class HurryUp : public Running
{

public:
	HurryUp(CollisionDetector collision);
	virtual ~HurryUp();
	void run();
	void updateTimer();
	
private:

};



#endif // HURRYUP_H