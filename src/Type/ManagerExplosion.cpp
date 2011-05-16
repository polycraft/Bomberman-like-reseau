#include "ManagerExplosion.h"


ManagerExplosion::ManagerExplosion(int id, int speed, int power, EExplose typeExplose, Map *map)
{
	this->id = id;
	this->speed = speed;
	this->power = power;
	this->typeExplosion = typeExplose;
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
	vector<Explosion*>::iterator it=this->listeExplosions.begin();
	while(it < this->listeExplosions.end())
	{
		(*it)->destroy();
		it++;
	}


}