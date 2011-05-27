#include "EffectFaster.h"

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
	double speed = this->bomberman->getProperty<double>(PB_vitesse);
	this->bomberman->setProperty<double>(PB_vitesse, speed+0.01);
}