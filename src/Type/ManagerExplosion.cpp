#include "ManagerExplosion.h"

ManagerExplosion::ManagerExplosion(int x, int y, int id, int speed, int power, GameType *gametype)
{
	this->x=x;
	this->y=y;
	this->id = id;
	this->speed = speed;
	this->power = power;
	this->powercurrent=0;
	this->gameType = gametype;
	this->nbEnd = 0; // nb de branches qui ont finis dexploser
	this->nbExploSide= 0;

	this->listeExplosionFlare.push_back(new ExplosionFlare(x,y,id, speed, power, T_Emitter, gametype, this));
	this->listeExplosionFlare.push_back(new ExplosionFlare(x,y,id, speed, power, T_Left, gametype, this));
	this->listeExplosionFlare.push_back(new ExplosionFlare(x,y,id, speed, power, T_Right, gametype, this));
	this->listeExplosionFlare.push_back(new ExplosionFlare(x,y,id, speed, power, T_Up, gametype, this));
	this->listeExplosionFlare.push_back(new ExplosionFlare(x,y,id, speed, power, T_Down, gametype, this));


}

ManagerExplosion::~ManagerExplosion()
{
	vector<ExplosionFlare*>::iterator it=this->listeExplosionFlare.begin();
	while(it < this->listeExplosionFlare.end())
	{
		delete *it;
		it++;
	}
}



void ManagerExplosion::addAnEnd()
{
	this->nbEnd++;//ajoute une branche qui a fini
	if( this->nbEnd == 5)
	{
		Timer::getTimer()->addListener(this,500);
	}
}


void ManagerExplosion::updateTimer(unsigned int delay)
{
	Timer::getTimer()->removeListener(this,500);
	this->gameType->destroyManagerExplosion(this);
}

