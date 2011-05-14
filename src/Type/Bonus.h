#ifndef BONUS_H
#define BONUS_H

#include "Type.h"

enum EBonus
{
	T_Faster,
	T_BombPlus,
	T_PowerPlus,
	T_MultiBomb
};

class Bonus : public Type
{

public:
	Bonus();
	~Bonus();
	EType getType();
	EBonus getBonus();

private:
	EBonus bonus;


};



#endif // BONUS_H