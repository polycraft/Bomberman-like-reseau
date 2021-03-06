#include "Bomb.h"
#include "../Engine/util/Timer.h"
#include "../GameType/GameType.h"
#include "../Engine/ManagerRessource.h"
#include "../Game.h"
#include "Bomberman.h"

using namespace Engine;

Bomb::Bomb(GameType* gameType,int idOwner, int time, int speed, int power):gameType(gameType)
{
	this->idOwner = idOwner;
	this->speed = speed;
	this->power = power;
	this->time = time;
	this->timeAnim = 50;
	this->upAnim = true;
	Timer::getTimer()->addListenerOnce(this,time);
	Timer::getTimer()->addListener(this,this->timeAnim);
	this->attach(ManagerRessource::getRessource("src/ressource/object/bomb.obj"),
	ManagerRessource::getRessource("src/ressource/texture/bomb.jpg"));
}

Bomb::~Bomb()
{
    Timer::getTimer()->removeListenerOnce(this,time);
	Timer::getTimer()->removeListener(this,this->timeAnim);
}

void Bomb::explode()
{
   // Timer::getTimer()->removeListenerOnce(this,time);

    updateTimer(time);
}

void Bomb::destroy()
{
	Object::destroy();

}

void Bomb::updateTimer(unsigned int delay)
{
	if(delay == this->time)
	{
		//Timer::getTimer()->removeListener(this,this->timeAnim);
		this->setVisible(false);
		this->gameType->explode(this,speed,power);
		this->destroy();
	}
	else
	{
		if(this->getZScale() >=1.5) this->upAnim = false;
		if(this->getZScale() <=1) this->upAnim = true;

		switch(this->upAnim)
		{
		case true:
			this->scale(0,0,0.1);
			break;
		case false:
			this->scale(0,0,-0.1);
			break;
		}
	}

}


EType Bomb::getType()
{
	return T_Bomb;
}

int Bomb::getIdOwner()
{
    return idOwner;
}

