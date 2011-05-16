#include "Explosion.h"

Explosion::Explosion(int id, int speed, int power, EExplose type)
{
	this->id = id;
	this->speed = speed;
	this->power = power;
	this->typeExplosion = type;

}

Explosion::~Explosion()
{

}


EType Explosion::getType()
{
	return T_Explosion;
}

