#include "Bonus.h"

#include "Effects/Effect.h"
#include "Effects/EffectFaster.h"
#include "Effects/EffectBombPlus.h"
#include "Effects/EffectPowerPlus.h"

#include "../Engine/ManagerRessource.h"
#include "../Engine/util/Timer.h"

using namespace Engine;

Bonus::Bonus(EBonus bonus)
{
	this->bonus = bonus;
	this->timeAnim = 50;
	this->upAnim = true;
	this->downAnim = false;
	Timer::getTimer()->addListener(this,this->timeAnim);

	switch(this->bonus)
	{
		case T_Faster:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bonus.obj"),
			ManagerRessource::getRessource("src/ressource/texture/bonus/bonusFaster.png"));
			this->effect = new EffectFaster();
		break;
		case T_BombPlus:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bonus.obj"),
			ManagerRessource::getRessource("src/ressource/texture/bonus/bonusBomb.png"));
			this->effect = new EffectBombPlus();
		break;
		case T_PowerPlus:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bonus.obj"),
			ManagerRessource::getRessource("src/ressource/texture/bonus/bonusPower.png"));
			this->effect = new EffectPowerPlus();
		break;
		default:

		break;
	}

}

Bonus::~Bonus()
{
    Timer::getTimer()->removeListener(this,this->timeAnim);
}

EType Bonus::getType()
{
	return T_Bonus;
}

EBonus Bonus::getTypeBonus()
{
	return this->bonus;
}

void Bonus::setEffect(Effect *effect)
{
	this->effect = effect;
}

Effect* Bonus::getEffect()
{
	return this->effect;
}

void Bonus::updateTimer(unsigned int delay)
{
	if(this->getTransZ()>= 10) this->upAnim = false;
	if(this->getTransZ()<= 0) this->upAnim = true;
	switch(this->upAnim)
	{
		case true :
			this->translation(0,0,0.5);
		break;

		case false :
			this->translation(0,0,-0.5);
		break;
	}
	this->rotate(0,0,5);

}
