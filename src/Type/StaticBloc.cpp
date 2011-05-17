#include "StaticBloc.h"

Cube* StaticBloc::staticBloc = NULL;

StaticBloc::StaticBloc()
{

	if(StaticBloc::staticBloc==NULL)
	{
		StaticBloc::staticBloc = new Cube(1);
	}
	this->attach(staticBloc);

	this->setTexture(ManagerRessource::getRessource<Texture>("src/ressource/texture/steel2.jpg"));
}

StaticBloc::~StaticBloc()
{
}


EType StaticBloc::getType()
{
	return T_StaticBloc;
}