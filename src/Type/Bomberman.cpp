#include "Bomberman.h"

Bomberman::Bomberman(map<EPropertyBomberman,Property*>& property)
{
    this->property=property;
}

Bomberman::Bomberman(int id)
{
	this->property[PB_id]=new Property(id);

	this->attach(ManagerRessource::getRessource("src/ressource/object/bombermanPause.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bomberman.jpg"));
	//chargement de sa position courir
	ManagerRessource::getRessource("src/ressource/object/bombermanRun.obj");
}

Bomberman::~Bomberman()
{
    map<EPropertyBomberman,Property*>::iterator it;

    for ( it=property.begin() ; it != property.end(); it++ )
    {
        delete (*it).second;
    }
}

EType Bomberman::getType()
{
	return T_Bomberman;
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
