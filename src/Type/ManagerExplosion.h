#ifndef MANAGEREXPLOSION_H
#define MANAGEREXPLOSION_H

#include "Type.h"
#include "Explosion.h"
#include "../Map.h"


class ManagerExplosion
{
	public:
		ManagerExplosion(int id, int speed, int power, EExplose typeExplose, Map *map);
		~ManagerExplosion();
		void nextExplose();
		void endExplose();
		
	private:
		vector<Explosion*> listeExplosions;
		int id;
		int speed;
		int power;
		EExplose typeExplosion;

};



#endif // MANAGEREXPLOSION_H