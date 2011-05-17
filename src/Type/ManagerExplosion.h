#ifndef MANAGEREXPLOSION_H
#define MANAGEREXPLOSION_H

#include "Type.h"
#include "Explosion.h"
#include "../Map.h"
#include "../Engine/util/Timer.h"

#include "../Engine/util/IObserverTimer.h"
#include "../GameType/GameType.h"


class ManagerExplosion : public IObserverTimer
{
	public:
		ManagerExplosion(int x, int y, int id, int speed, int power, EExplose typeExplose, GameType *gametype);
		~ManagerExplosion();
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
		EExplose typeExplosion;
		bool isEnd;
		GameType *gameType;

};



#endif // MANAGEREXPLOSION_H