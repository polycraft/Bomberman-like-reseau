#ifndef GAMETYPE_H
#define GAMETYPE_H
class Bomb;
#include "../Type/Bomb.h"

class GameType
{

public:
	GameType();
	virtual ~GameType();
	virtual void explode(Bomb* bomb,int speed,int power)=0;


private:
	int partTime;

};



#endif // GAMETYPE_H
