#include "Explosion.h"

Explosion::Explosion(EExplose type)
{
	this->typeExplosion = type;
	switch(this->typeExplosion)
	{
	case T_Emitter:
		this->attach(ManagerRessource::getRessource("src/ressource/object/emitterExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/emitterExplosion.jpg"));
		break;

		case T_Left:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.jpg"));
			this->setRotation(0,180,0);
		break;

		case T_Right:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.jpg"));
			this->setRotation(0,180,0);
		break;

		case T_Up:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.jpg"));
			this->setRotation(0,180,90);
		break;

		case T_Down:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.jpg"));
			this->setRotation(0,180,90);
		break;

		case T_End:
			this->attach(ManagerRessource::getRessource("src/ressource/object/endExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/endExplosion.jpg"));
		break;
	}
}

Explosion::~Explosion()
{

}


EType Explosion::getType()
{
	return T_Explosion;
}

void Explosion::changeExplose(EExplose typeExplose)
{
	this->typeExplosion = typeExplose;

	switch(this->typeExplosion)
	{
		case T_Left:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.jpg"));
		break;

		case T_Right:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.jpg"));
		break;

		case T_Up:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.jpg"));
			this->setRotation(0,0,90);
		break;

		case T_Down:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.jpg"));
			this->setRotation(0,0,90);
		break;
	}
}