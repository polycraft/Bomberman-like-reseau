#include "EffectBombPlus.h"

#include "../Bomberman.h"

EffectBombPlus::EffectBombPlus()
{
}

EffectBombPlus::~EffectBombPlus()
{
}

void EffectBombPlus::enableEffect(Bomberman *bomberman)
{
	this->bomberman = bomberman;
	this->bomberman->setProperty<int>(PB_nbBomb, this->bomberman->getProperty<int>(PB_nbBomb)+1);
}
