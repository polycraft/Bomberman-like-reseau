#include "Bomberman.h"


Bomberman::Bomberman(int id)
{
	this->id = id;
	this->attach(ManagerRessource::getRessource("src/ressource/object/bombermanPause.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bomberman.jpg"));
	//chargement de sa position courir
	ManagerRessource::getRessource("src/ressource/object/bombermanRun.obj");
}

Bomberman::~Bomberman()
{
}

EType Bomberman::getType()
{
	return T_Bomberman;
}

int Bomberman::getId()
{
    return id;
}

void Bomberman::setRunning()
{
	this->attach(ManagerRessource::getRessource("src/ressource/object/bombermanRun.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bomberman.jpg"));
}

void Bomberman::setPause()
{
		this->attach(ManagerRessource::getRessource("src/ressource/object/bombermanPause.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bomberman.jpg"));
}
