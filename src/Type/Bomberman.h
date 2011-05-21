#ifndef BOMBERMAN_H
#define BOMBERMAN_H
class Bomberman;
#include "Type.h"
#include "../Map.h"
#include <map>
#include "Property.h"
#include "../Engine/util/IObserverTimer.h"
#include "../Engine/Text.h"

typedef enum EPropertyBomberman
{
    PB_id=0,
    PB_bombPower=1,
    PB_vitesse=2,
    PB_nbBomb=3,
    PB_nbBombMax=4,
    PB_timerBomb=5,
    PB_timerPutBomb=6,
    PB_vitesseExplode=7,
    PB_life=8,
    PB_canPutBomb=9,
    PB_invinsible=10,
    PB_timeInvinsible=11
} EPropertyBomberman;

class Bomberman : public Type, public IObserverTimer
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

	void setInvinsible(int time);
	void lostLife(int nb=1);

	virtual void setCoordonnes(double x,double y,double z);

    void setName(string &name);
    void setName(char *name);
    Text* getName();
protected:
    map<EPropertyBomberman,Property*> property;
    Text name;
};



#endif // BOMBERMAN_H
