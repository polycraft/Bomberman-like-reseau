#ifndef BOMB_H
#define BOMB_H

#include "Type.h"
#include "../Engine/util/IObserverTimer.h"

class GameType;

class Bomb : public Type, public Engine::IObserverTimer
{

public:
	Bomb(GameType* gameType,int idOwner, int time, int speed, int power);
	~Bomb();
	EType getType();
	void updateTimer(unsigned int);
	int getIdOwner();
	void explode();
	void destroyTimeAnim(){};
	void destroy();

private:
	int idOwner;

	GameType* gameType;
	int speed;
	int power;
	int time;
	bool upAnim;
	int timeAnim;

};



#endif // BOMB_H
