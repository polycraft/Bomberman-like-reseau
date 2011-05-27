#include "EffectPowerPlus.h"

EffectPowerPlus::EffectPowerPlus()
{
}

EffectPowerPlus::~EffectPowerPlus()
{
}

void EffectPowerPlus::enableEffect(Bomberman *bomberman)
{
	this->bomberman = bomberman;
	this->bomberman->setProperty<int>(PB_bombPower, this->bomberman->getProperty<int>(PB_bombPower) + 1);
}