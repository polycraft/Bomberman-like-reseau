#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Type.h"

class Explosion : public Type
{

public:
	Explosion(int id, int speed, int power);
	~Explosion();
	EType getType();
	void updateTimer();

private:
	int id;
	int speed;
	int power;



};



#endif // EXPLOSION_H