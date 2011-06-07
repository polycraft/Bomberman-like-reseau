#ifndef STATICBLOC_H
#define STATICBLOC_H

#include "Type.h"
#include "../Engine/GraphicEngine/Cube.h"

class StaticBloc : public Type
{

public:
	StaticBloc();
	~StaticBloc();
	EType getType();

private:
	static Engine::Cube* staticBloc;
};



#endif // STATICBLOC_H
