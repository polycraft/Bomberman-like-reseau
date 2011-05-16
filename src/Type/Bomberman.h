#ifndef BOMBERMAN_H
#define BOMBERMAN_H
class Bomberman;
#include "Type.h"
#include "../Map.h"

class Bomberman : public Type
{

public:
	Bomberman(int id,int x,int y);
	Bomberman(int id,struct SCoordinate coord);
	~Bomberman();
	EType getType();

private:
	int id;

    void init(int id,int x,int y);


};



#endif // BOMBERMAN_H
