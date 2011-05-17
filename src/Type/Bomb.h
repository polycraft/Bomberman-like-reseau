#ifndef BOMB_H
#define BOMB_H
class GameType;
#include "Type.h"
#include "../Engine/util/Timer.h"
#include "../Engine/util/IObserverTimer.h"
#include "../GameType/GameType.h"

//using namespace Engine;

class Bomb : public Type, public IObserverTimer
{

public:
	Bomb(GameType* gameType,int idOwner, int time, int speed, int power);
	~Bomb();
	EType getType();
	void updateTimer(unsigned int);
	int getIdOwner();
	void explode();

private:
	int idOwner;

	GameType* gameType;
	int speed;
	int power;
	int time;

};



#endif // BOMB_H
