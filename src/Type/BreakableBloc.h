#ifndef BREAKABLEBLOC_H
#define BREAKABLEBLOC_H

#include "Type.h"

class BreakableBloc : public Type
{

public:
	BreakableBloc();
	~BreakableBloc();
	EType getType();

private:
	static Cube* Breakbloc;


};



#endif // BREAKABLEBLOC_H