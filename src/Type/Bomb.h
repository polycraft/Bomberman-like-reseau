#ifndef BOMB_H
#define BOMB_H

#include "Type.h"
#include "../Engine/util/Timer.h"
#include "../Engine/util/IObserverTimer.h"
#include "../GameType/GameType.h"

//using namespace Engine;

class Bomb : public Type, IObserverTimer
{

public:
	Bomb(int idOwner, int time, int speed, int power);
	~Bomb();
	EType getType();
	void updateTimer();

private:
	int idOwner;

	GameType* gameType;
	int speed;
	int power;

};



#endif // BOMB_H