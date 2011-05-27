#include "Bonus.h"
#include "Effects/EffectFaster.h"
#include "Effects/EffectBombPlus.h"
#include "Effects/EffectPowerPlus.h"
Bonus::Bonus(EBonus bonus)
{
	this->bonus = bonus;
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
	}
}

Bonus::~Bonus()
{
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