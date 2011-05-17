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
		this->gameType->getGame()->getMap()->addObject(this->listeExplosions.back(),this->x,this->y, T_Dyn);
	}
	else
	{
		this->listeExplosions.push_back(new Explosion(T_End));
		this->gameType->getGame()->getMap()->addObject(this->listeExplosions.back(),this->x,this->y, T_Dyn);
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
		double x, y;
		x=this->x;
		y=this->y;
		switch(this->typeExplosion)
		{
		case T_Left:
			x-=1;
			break;
	    case T_Right:
			x+=1;
			break;
        case T_Up:
            y+=1;
			break;
        case T_Down:
            y-=1;
        break;
		}

		this->gameType->getGame()->getMap()->addObject(this->listeExplosions.back(),x,y, T_Dyn);
		
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
		this->gameType->destroyManagerExplosion(this);

	}

}

int ManagerExplosion::getID()
{
	return this->id;
}