#include "StaticBloc.h"

Cube* StaticBloc::bloc = NULL;


StaticBloc::StaticBloc()
{

	if(StaticBloc::bloc==NULL)
	{
		StaticBloc::bloc = new Cube(1,ManagerRessource::getRessource<Texture>("src/ressource/texture/box.jpg"));
	}
	this->attach(bloc);
}

StaticBloc::~StaticBloc()
{
}


EType StaticBloc::getType()
{
	return T_StaticBloc;
}