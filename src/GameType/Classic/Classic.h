#ifndef CLASSIC_H
#define CLASSIC_H

#include "../GameType.h"
#include "../../CollisionDetector.h"

class Classic : public GameType
{

public:
	Classic(CollisionDetector collision);
	virtual ~Classic();
	void nextPhase(int phase);
	virtual void explode(Bomb* bomb,int speed,int power);
	
	
private:
	int partTime;

};



#endif // CLASSIC_H