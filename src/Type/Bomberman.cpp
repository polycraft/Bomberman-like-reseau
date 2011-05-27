#include "Bomberman.h"
#include "../Engine/util/Timer.h"

Bomberman::Bomberman(map<EPropertyBomberman,Property*>& property):name(TT_Text3D)
{
    this->property=property;
}

Bomberman::Bomberman(int id):name(TT_Text3D)
{
	this->property[PB_id]=new Property(id);

	this->attach(ManagerRessource::getRessource("src/ressource/object/bombermanPause.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bomberman.jpg"));
	//chargement de sa position courir
	ManagerRessource::getRessource("src/ressource/object/bombermanRun.obj");
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

void Bomberman::setName(string &name)
{
    this->name.setText(name);
}

void Bomberman::setName(char *name)
{
    this->name.setText(name);
}

Text* Bomberman::getName()
{
    return &this->name;
}

void Bomberman::setCoordonnes(double x,double y,double z)
{
    ObjectMovable::setCoordonnes(x,y,z);
    this->name.setCoord(x,y,z+2.5);
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