#ifndef BOMB_H
#define BOMB_H

#include "Type.h"
#include "../Engine/util/Timer.h"

class Bomb : public Type
{

public:
	Bomb(int idOwner, int time, int speed, int power);
	~Bomb();
	EType getType();
	void updateTimer();

private:
	int idOwner;
	GameType gameType;
	int speed;
	int power;

}



#endif // BOMBERMAN_H