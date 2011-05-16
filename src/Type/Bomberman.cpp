#include "Bomberman.h"


Bomberman::Bomberman(int id)
{
	this->id = id;
	this->attach(ManagerRessource::getRessource("src/ressource/object/bomberman.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bomberman.jpg"));
}

Bomberman::~Bomberman()
{
}

EType Bomberman::getType()
{
	return T_Bomberman;
}
