#ifndef EXPLOSIONFLARE_H
#define EXPLOSIONFLARE_H

class ExplosionFlare;

#include "Type.h"
#include "Explosion.h"
#include "ManagerExplosion.h"
#include "../Map.h"
#include "../Engine/util/Timer.h"

#include "../Engine/util/IObserverTimer.h"
#include "../GameType/GameType.h"


class ExplosionFlare : public IObserverTimer
{
	public:
		ExplosionFlare(int x, int y, int id, int speed, int power, EExplose typeExplose, GameType *gametype, ManagerExplosion *manager);
		~ExplosionFlare();
		void nextExplose();
		void endExplose();
		EExplose getType();
		void updateTimer(unsigned int delay);
		int getID();

	private:
		int x;
		int y;
		vector<Explosion*> listeExplosions;
		int id;
		int speed;
		int power;
		int powercurrent;
		EExplose typeExplosion;
		bool isEnd;
		GameType *gameType;
		ManagerExplosion *manager;

};



#endif // EXPLOSIONFLARE_H
