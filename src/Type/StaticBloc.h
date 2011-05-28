#ifndef STATICBLOC_H
#define STATICBLOC_H

#include "Type.h"

class StaticBloc : public Type
{

public:
	StaticBloc();
	~StaticBloc();
	EType getType();

	void destroyTimeAnim(){};

private:
	static Cube* staticBloc;
};



#endif // STATICBLOC_H