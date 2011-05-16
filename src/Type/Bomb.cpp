#include "Bomb.h"

Bomb::Bomb(int idOwner, int time, int speed, int power)
{
	this->idOwner = idOwner;
	this->speed = speed;
	this->power = power;
	Timer::getTimer()->addListenerOnce(this,time);
	this->attach(ManagerRessource::getRessource("src/ressource/object/bomb.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bomb.jpg"));

}

Bomb::~Bomb()
{

}


void Bomb::updateTimer(unsigned int delay)
{
	this->gameType->explode(this,speed,power);
}


EType Bomb::getType()
{
	return T_Bomb;
}
