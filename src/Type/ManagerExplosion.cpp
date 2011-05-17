#include "ManagerExplosion.h"


ManagerExplosion::ManagerExplosion(int x, int y, int id, int speed, int power, EExplose typeExplose, GameType *gametype)
{
	this->id = id;
	this->speed = speed;
	this->power = power;
	this->typeExplosion = typeExplose;
	this->isEnd = false;
	this->gameType = gametype;

	Timer::getTimer()->addListener(this,500/this->speed);

	if(this->typeExplosion == T_Emitter)
	{
		this->listeExplosions.push_back(new Explosion(T_Emitter));
	}
	else
	{
		this->listeExplosions.push_back(new Explosion(T_End));
	}


}

ManagerExplosion::~ManagerExplosion()
{
	vector<Explosion*>::iterator it=this->listeExplosions.begin();
	while(it < this->listeExplosions.end())
	{
		(*it)->destroy();
		it++;
	}
}

void ManagerExplosion::nextExplose()
{
	if(this->typeExplosion != T_Emitter)
	{
		this->listeExplosions.back()->changeExplose(this->typeExplosion);
		this->listeExplosions.push_back(new Explosion(T_End));
	}
}

void ManagerExplosion::endExplose()
{
	Timer::getTimer()->removeListener(this,500/this->speed);
	Timer::getTimer()->addListener(this,1000);
}

EExplose ManagerExplosion::getType()
{
	return this->typeExplosion;
}

void ManagerExplosion::updateTimer(unsigned int delay)
{
	if(!this->isEnd)
	{
		this->gameType->updateExplosion(this,this->power,this->x,this->y);
	}
	else
	{
		Timer::getTimer()->removeListener(this,1000);
		this->gameType->destroyManagerExplose(this);

	}

}

int ManagerExplosion::getID()
{
	return this->id;
}