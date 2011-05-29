#include "BreakableBloc.h"

#include "../Engine/ManagerRessource.h"
#include "../Engine/GraphicEngine/Cube.h"

using namespace Engine;

Cube* BreakableBloc::Breakbloc = NULL;

BreakableBloc::BreakableBloc()
{
	if(BreakableBloc::Breakbloc==NULL)
	{
		BreakableBloc::Breakbloc = new Cube(1);
	}
	this->attach(Breakbloc);
	this->setTexture(ManagerRessource::getRessource<Texture>("src/ressource/texture/box2.jpg"));
}

BreakableBloc::~BreakableBloc()
{

}

EType BreakableBloc::getType()
{
	return T_BreakableBloc;
}
