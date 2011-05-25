#ifndef BONUS_H
#define BONUS_H

class Bonus;
#include "Type.h"
#include "Effects/Effect.h"
#include "Effects/EffectFaster.h"


typedef enum EBonus
{
	T_Faster,
	T_BombPlus,
	T_PowerPlus
};

class Bonus : public Type
{

public:
	Bonus(EBonus bonus);
	~Bonus();
	EType getType();
	EBonus getTypeBonus();
	void setEffect(Effect *effect);
	Effect* getEffect();

private:
	EBonus bonus;
	Effect *effect;


};



#endif // BONUS_H