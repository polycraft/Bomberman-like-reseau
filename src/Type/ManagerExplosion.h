#ifndef MANAGEREXPLOSION_H
#define MANAGEREXPLOSION_H

class ManagerExplosion;

#include "Type.h"
#include "Explosion.h"
#include "ExplosionFlare.h"
#include "../Map.h"
#include "../Engine/util/Timer.h"
#include "../Engine/util/IObserverTimer.h"
#include "../GameType/GameType.h"


class ManagerExplosion : public IObserverTimer
{
	public:
		ManagerExplosion(int x, int y, int id, int speed, int power, GameType *gametype);
		~ManagerExplosion();
		void addAnEnd();
		void updateTimer(unsigned int delay);
		int getID();

	private:
		int x;
		int y;
		vector<ExplosionFlare*> listeExplosionFlare;
		int id;
		int speed;
		int power;
		int powercurrent;
		GameType *gameType;
		int nbEnd;
		int nbExploSide;

};


#endif //MANAGEREXPLOSION_H