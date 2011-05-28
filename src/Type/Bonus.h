#ifndef BONUS_H
#define BONUS_H

class Bonus;
#include "Effects/Effect.h"
#include "Type.h"
#include "../Engine/util/IObserverTimer.h"
#include "../Engine/util/Timer.h"






typedef enum EBonus
{
	T_None,
	T_Faster,
	T_BombPlus,
	T_PowerPlus
};

class Bonus : public Type, IObserverTimer
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