#include "Bomberman.h"
#include "../Engine/util/Timer.h"

#include "Bonus.h"
#include "../Map.h"

#include "../Engine/ManagerRessource.h"
#include <cmath>

using namespace Engine;

Bomberman::Bomberman(map<EPropertyBomberman,Property*>& property):name(TT_Text3D)
{
    this->property=property;
    name.setColor(255,255,255,255);
}

Bomberman::Bomberman(int id):name(TT_Text3D)
{
	this->property[PB_id]=new Property(id);

	this->attach(ManagerRessource::getRessource("src/ressource/object/bombermanPause.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bomberman.jpg"));
	//chargement de sa position courir
	ManagerRessource::getRessource("src/ressource/object/bombermanRun.obj");

	name.setColor(255,255,255,255);
}

Bomberman::~Bomberman()
{
    map<EPropertyBomberman,Property*>::iterator it;

    for ( it=property.begin() ; it != property.end(); it++ )
    {
        delete (*it).second;
    }

	//destruction des bonus
	set<Bonus*>::iterator it2;
	for(it2 = this->bonusList.begin() ; it2 != this->bonusList.end() ; it++)
	{
		//delete (*it);
	}

}

EType Bomberman::getType()
{
	return T_Bomberman;
}

void Bomberman::setRunning()
{
	this->attach(ManagerRessource::getRessource("src/ressource/object/bombermanRun.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bomberman.jpg"));
}

void Bomberman::setPause()
{
		this->attach(ManagerRessource::getRessource("src/ressource/object/bombermanPause.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bomberman.jpg"));
}

void Bomberman::updateTimer(unsigned int delay)
{
    if(delay==this->getProperty<int>(PB_timeInvincible))
    {
        this->setProperty<int>(PB_invincible,false);
        Timer::getTimer()->removeListener(this,100);
    }
    else if(delay==100)
    {
        this->setVisible(!this->getVisible());
    }
    else
    {
        this->setProperty<bool>(PB_canPutBomb,true);
    }
}

void Bomberman::setInvincible(int time)
{
    if(this->getProperty<bool>(PB_invincible))
    {
        Timer::getTimer()->removeListenerOnce(this,this->getProperty<int>(PB_timeInvincible));
    }
    Timer::getTimer()->addListenerOnce(this,time);
    this->setProperty<int>(PB_timeInvincible,time);
    this->setProperty<int>(PB_invincible,true);

    Timer::getTimer()->addListener(this,100);
}

void Bomberman::lostLife(int nb)
{
    setProperty<int>(PB_life,getProperty<int>(PB_life)-nb);
}

void Bomberman::setName(string &name,double mapWidth,double mapHeight)
{
    this->name.setText(name);
    this->mapWidth=mapWidth;
    this->mapHeight=mapHeight;
}

void Bomberman::setName(char *name,double mapWidth,double mapHeight)
{
    this->name.setText(name);
    this->mapWidth=mapWidth;
    this->mapHeight=mapHeight;
}

Text* Bomberman::getName()
{
    return &(this->name);
}

void Bomberman::setCoordonnes(double x,double y,double z)
{
    ObjectMovable::setCoordonnes(x,y,z);
    this->moveName();
}

void Bomberman::translation(double x,double y,double z)
{
    ObjectMovable::translation(x,y,z);
    this->moveName();
}

void Bomberman::setTransX(double x)
{
    ObjectMovable::setTransX(x);
    this->moveName();
}

void Bomberman::setTransY(double y)
{
    ObjectMovable::setTransY(y);
    this->moveName();
}
void Bomberman::setTransZ(double z)
{
    ObjectMovable::setTransZ(z);
    this->moveName();
}

void Bomberman::moveName()
{
    double b =(mapHeight*10.0);
    double Y = 	this->getTransY();
    double X = 	this->getTransX();
    double H = sqrt(150*150+b*b);
    double I1 = 150*H/b;
    double I2 = 150*150/b;
    name.setCoord(X-mapWidth*10/2-10,10*H/b-I1*((b-Y)/(b+I2)),-H*(1-(b-Y)/(b+I2)));
}


void Bomberman::addBonus(Bonus *bonus)
{
	this->bonusList.insert(bonus);
}

void Bomberman::remove(Bonus *bonus)
{
	set<Bonus*>::iterator it;
	for(it = this->bonusList.begin() ; it != this->bonusList.end() ; it++)
	{
		if((*it) == bonus)
		{
			//suppression a voir si besoin
		}
	}
}
