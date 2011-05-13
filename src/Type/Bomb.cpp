#include "Bomb.h"

Bomb::Bomb(int idOwner, int time, int speed, int power)
{
	this->idOwner = idOwner;
	this->speed = speed;
	this->power = power;

	Timer::getTimer()->addListenerOnce(this,time);
}


void Bomb::updateTimer()
{
	this->gameType->explose(this,speed,power);
}


EType Bomb::getType()
{
	return T_Bomb;
}