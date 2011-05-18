#include "ManagerExplosion.h"


ManagerExplosion::ManagerExplosion(int x, int y, int id, int speed, int power, EExplose typeExplose, GameType *gametype)
{
	this->id = id;
	this->speed = speed;
	this->power = power;
	this->powercurrent=0;
	this->typeExplosion = typeExplose;
	this->isEnd = false;
	this->gameType = gametype;
	this->x=x;
	this->y=y;

	Timer::getTimer()->addListener(this,500/this->speed);

	if(this->typeExplosion == T_Emitter)
	{
	    this->powercurrent=0;
		this->listeExplosions.push_back(new Explosion(T_Emitter,x,y));
		this->gameType->getGame()->getMap()->addObject(this->listeExplosions.back(),this->x,this->y, T_Dyn);
	}
	else
	{
	    this->powercurrent=1;
		this->listeExplosions.push_back(new Explosion(T_End,x,y));
		this->gameType->getGame()->getMap()->addObject(this->listeExplosions.back(),this->x,this->y, T_Dyn);
	}


}

ManagerExplosion::~ManagerExplosion()
{
	vector<Explosion*>::iterator it=this->listeExplosions.begin();
	while(it < this->listeExplosions.end())
	{
		(*it)->destroy();
		this->gameType->getGame()->getMap()->set(NULL,(*it)->getX(),(*it)->getY());
		it++;
	}
}

void ManagerExplosion::nextExplose()
{
	if(this->typeExplosion != T_Emitter)
	{
		int x, y;
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

		this->listeExplosions.back()->changeExplose(this->typeExplosion);
		this->listeExplosions.push_back(new Explosion(T_End,x,y));

		this->gameType->getGame()->getMap()->addObject(this->listeExplosions.back(),x,y, T_Dyn);
	}
	else
	{
	    endExplose();
	}
}

void ManagerExplosion::endExplose()
{
	this->isEnd=true;
	Timer::getTimer()->removeListener(this,500/this->speed);
	Timer::getTimer()->addListenerOnce(this,1000);
}

EExplose ManagerExplosion::getType()
{
	return this->typeExplosion;
}

void ManagerExplosion::updateTimer(unsigned int delay)
{
	cout << "update Manager" << endl;
	if(delay == 500/this->speed )
	{
		this->gameType->updateExplosion(this,this->powercurrent,this->x,this->y);
        this->powercurrent++;
	}
	else if(delay==1000)
	{
		this->gameType->destroyManagerExplosion(this);
	}

}

int ManagerExplosion::getID()
{
	return this->id;
}
