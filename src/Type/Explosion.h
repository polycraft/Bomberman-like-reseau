#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Type.h"

enum EExplose
{
	T_Emiter,
	T_Left,
	T_Right,
	T_Up,
	T_Down,
	T_End
};

class Explosion : public Type
{

public:
	Explosion(int id, int speed, int power, EExplose type);
	~Explosion();
	EType getType();
	void updateTimer();

private:
	int id;
	int speed;
	int power;
	EExplose typeExplosion;



};



#endif // EXPLOSION_H