#ifndef BREAKABLEBLOC_H
#define BREAKABLEBLOC_H

#include "Type.h"
#include "../Engine/GraphicEngine/Cube.h"

class BreakableBloc : public Type
{

public:
	BreakableBloc();
	~BreakableBloc();
	EType getType();

private:
	static Engine::Cube* Breakbloc;


};



#endif // BREAKABLEBLOC_H
