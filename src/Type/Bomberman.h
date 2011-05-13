#ifndef BOMBERMAN_H
#define BOMBERMAN_H

#include "Type.h"

class Bomberman : public Type
{

public:
	Bomberman(int id);
	~Bomberman();
	EType getType();

private:
	int id;



}



#endif // BOMBERMAN_H