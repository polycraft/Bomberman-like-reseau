#include "Bonus.h"

Bonus::Bonus()
{
}

Bonus::~Bonus()
{
}

EType Bonus::getType()
{
	return T_Bonus;
}

EBonus Bonus::getBonus()
{
	return this->bonus;
}