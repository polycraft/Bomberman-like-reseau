#ifndef BOMBERMAN_H
#define BOMBERMAN_H
class Bomberman;
#include "Type.h"
#include "../Map.h"

class Bomberman : public Type
{

public:
	Bomberman(int id);
	~Bomberman();
	EType getType();
	int getId();

private:
	int id;


};



#endif // BOMBERMAN_H
