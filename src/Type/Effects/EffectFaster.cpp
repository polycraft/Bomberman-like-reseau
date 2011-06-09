#include "EffectFaster.h"

#include "../Bomberman.h"

EffectFaster::EffectFaster()
{
	this->bomberman = bomberman;
}

EffectFaster::~EffectFaster()
{
}

void EffectFaster::enableEffect(Bomberman *bomberman)
{
	this->bomberman = bomberman;
	double speed = this->bomberman->getProperty<double>(PB_speed);
	this->bomberman->setProperty<double>(PB_speed, 0.08);
}
