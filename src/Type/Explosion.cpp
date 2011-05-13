#include "Explosion.h"

Explosion::Explosion(int id, int speed, int power)
{
	this->id = id;

}

Explosion::~Explosion()
{

}


EType Explosion::getType()
{
	return T_Explosion;
}

