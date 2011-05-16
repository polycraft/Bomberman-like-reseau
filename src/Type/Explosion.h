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
	Explosion(EExplose type);
	~Explosion();
	EType getType();
	void updateTimer();

	void changeExplose(EExplose typeExplose);

private:
	EExplose typeExplosion;



};



#endif // EXPLOSION_H