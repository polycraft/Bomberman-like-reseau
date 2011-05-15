#ifndef STATICBLOC_H
#define STATICBLOC_H

#include "Type.h"

class StaticBloc : public Type
{

public:
	StaticBloc();
	~StaticBloc();
	EType getType();

private:
	static Cube* bloc;
};



#endif // STATICBLOC_H