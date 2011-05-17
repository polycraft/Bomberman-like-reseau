#include "Bomb.h"

Bomb::Bomb(GameType* gameType,int idOwner, int time, int speed, int power):gameType(gameType)
{
	this->idOwner = idOwner;
	this->speed = speed;
	this->power = power;
	this->time = time;
	Timer::getTimer()->addListenerOnce(this,time);
	this->attach(ManagerRessource::getRessource("src/ressource/object/bomb.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bomb.jpg"));
}

Bomb::~Bomb()
{

}

void Bomb::explode()
{
    Timer::getTimer()->removeListenerOnce(this,time);
    updateTimer(time);
}

void Bomb::updateTimer(unsigned int delay)
{
	this->setVisible(false);
	this->gameType->explode(this,speed,power);
	this->destroy();
}


EType Bomb::getType()
{
	return T_Bomb;
}

int Bomb::getIdOwner()
{
    return idOwner;
}
