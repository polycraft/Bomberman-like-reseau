#ifndef BOMBERMAN_H
#define BOMBERMAN_H

#include "Type.h"

#include <map>
#include <string>
#include "Property.h"
#include "../Engine/util/IObserverTimer.h"
#include "../Engine/Text.h"


class Bonus;

typedef enum EPropertyBomberman
{
    PB_id=0,
    PB_bombPower=1,
    PB_speed=2,
    PB_nbBomb=3,
    PB_nbBombMax=4,
    PB_timerBomb=5,
    PB_timerPutBomb=6,
    PB_speedExplode=7,
    PB_life=8,
    PB_canPutBomb=9,
    PB_invincible=10,
    PB_timeInvincible=11
} EPropertyBomberman;

class Bomberman : public Type, public Engine::IObserverTimer
{

public:
    Bomberman(map<EPropertyBomberman,Property*>& property);
	Bomberman(int id);
	~Bomberman();
	EType getType();

	template <typename T>const T& getProperty(EPropertyBomberman prop)
    {
        return this->property[prop]->getValue<T>();
    }

    template <typename T> void setProperty(EPropertyBomberman prop,T val)
    {
        map<EPropertyBomberman,Property*>::iterator it=this->property.find(prop);

        //Nouveau élément
        if(it==this->property.end())
        {
            this->property[prop]=new Property(val);
        }
        else
        {
            (*it).second->setValue<T>(val);
        }
    }

	void setRunning();
	void setPause();

	void updateTimer(unsigned int delay);

	void setInvincible(int time);
	void lostLife(int nb=1);

	virtual void setCoordonnes(double x,double y,double z);
	virtual void translation(double x,double y,double z);
	virtual void setTransX(double x);
    virtual void setTransY(double y);
    virtual void setTransZ(double z);

    void setName(std::string &name,double mapWidth,double mapHeight);
    void setName(char *name,double mapWidth,double mapHeight);
    Engine::Text* getName();

	void addBonus(Bonus *bonus);
	void remove(Bonus *bonus);

protected:
    void moveName();

    std::map<EPropertyBomberman,Property*> property;
    Engine::Text name;
	set<Bonus*> bonusList;

	double mapWidth;
	double mapHeight;
};



#endif // BOMBERMAN_H
