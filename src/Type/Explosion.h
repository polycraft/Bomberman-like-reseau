#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Type.h"

enum EExplose
{
	T_Emitter,
	T_Left,
	T_Right,
	T_Up,
	T_Down,
	T_End
};

class Explosion : public Type
{

public:
	Explosion(EExplose type,int x,int y);
	~Explosion();
	EType getType();
	void updateTimer();

	void changeExplose(EExplose typeExplose);

	int getX();
	int getY();

private:
	EExplose typeExplosion;
    int x;
    int y;


};



#endif // EXPLOSION_H
