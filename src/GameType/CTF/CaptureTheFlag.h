#ifndef CTF_H
#define CTF_H

#include "../GameType.h"
#include "../../CollisionDetector.h"

class CaptureTheFlag : public GameType
{

public:
	CaptureTheFlag(CollisionDetector collision);
	virtual ~CaptureTheFlag();
	void nextPhase(int phase);
	virtual void explode(Bomb* bomb,int speed,int power);
	
	
private:
	int partTime;

};



#endif // CTF_H