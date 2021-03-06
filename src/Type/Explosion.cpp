#include "Explosion.h"

#include "../Engine/ManagerRessource.h"
#include "ExplosionFlare.h"

using namespace Engine;

Explosion::Explosion(EExplose type,int x,int y, ExplosionFlare *explosionOwner):x(x),y(y)
{
	this->explosionOwner = explosionOwner;
	this->typeExplosion = type;
	switch(this->typeExplosion)
	{
	case T_Emitter:
		this->attach(ManagerRessource::getRessource("src/ressource/object/emitterExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/emitterExplosion.png"));
		break;

		case T_Left:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.png"));

		break;

		case T_Right:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.png"));

		break;

		case T_Up:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.png"));
			this->setRotation(0,0,90);
		break;

		case T_Down:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.png"));
			this->setRotation(0,0,90);
		break;

		case T_End:
			this->attach(ManagerRessource::getRessource("src/ressource/object/endExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/endExplosion.png"));
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

ExplosionFlare* Explosion::getExplosionFlare()
{
	return this->explosionOwner;
}


void Explosion::changeExplose(EExplose typeExplose)
{
	this->typeExplosion = typeExplose;

	switch(this->typeExplosion)
	{
		case T_Left:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.png"));
		break;

		case T_Right:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.png"));
		break;

		case T_Up:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.png"));
			this->setRotation(0,0,90);
		break;

		case T_Down:
			this->attach(ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.png"));
			this->setRotation(0,0,90);
		break;

		default:

		break;
	}
}

int Explosion::getX()
{
    return x;
}

int Explosion::getY()
{
    return y;
}
