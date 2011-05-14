#ifndef GAMETYPE_H
#define GAMETYPE_H

#include "../Type/Bomb.h"

class GameType
{

public:
	GameType();
	virtual ~GameType();
	virtual void explode(Bomb bomb,int speed,int power);
	
	
private:
	int partTime;

};



#endif // GAMETYPE_H