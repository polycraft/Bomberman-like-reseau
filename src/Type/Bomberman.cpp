#include "Bomberman.h"


Bomberman::Bomberman(int id,int x,int y)
{
	init(id,x,y);
}

Bomberman::Bomberman(int id,SCoordinate coord)
{
    init(id,coord.x,coord.y);
}

void Bomberman::init(int id,int x,int y)
{
    this->id = id;
	this->attach(ManagerRessource::getRessource("src/ressource/object/bomberman.obj"),
		ManagerRessource::getRessource("src/ressource/texture/bomberman.jpg"));

    //Calcule des coordonnées
    this->setCoordonnes(10*x+15,10*y+15,0);
}

Bomberman::~Bomberman()
{
}

EType Bomberman::getType()
{
	return T_Bomberman;
}
