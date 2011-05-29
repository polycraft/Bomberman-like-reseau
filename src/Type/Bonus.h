#ifndef BONUS_H
#define BONUS_H

#include "Type.h"
#include "../Engine/util/IObserverTimer.h"
#include "../Engine/util/Timer.h"



class Effect;


typedef enum EBonus
{
	T_None,
	T_Faster,
	T_BombPlus,
	T_PowerPlus
} EBonus;

class Bonus : public Type, Engine::IObserverTimer
{

public:
	Bonus(EBonus bonus);
	~Bonus();
	void updateTimer(unsigned int delay);
	EType getType();
	EBonus getTypeBonus();
	void setEffect(Effect *effect);
	Effect* getEffect();
	void destroyTimeAnim();

private:
	EBonus bonus;
	Effect *effect;
	bool upAnim;
	bool downAnim;
	int timeAnim;


};



#endif // BONUS_H
