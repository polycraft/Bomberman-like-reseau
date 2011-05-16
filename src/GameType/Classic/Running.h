#ifndef RUNNING_H
#define RUNNING_H

#include "PhaseClassic.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		class Running : public PhaseClassic
		{

		public:
			Running(GameTypeSpace::Classic *gameType,CollisionDetector *collision);
			virtual ~Running();
			void init();
			virtual void run();
			virtual void updateTimer();
			void executeAction(const Engine::stateEvent &event);
			virtual void updateRecv(Socket *,const char*,int size);

		};
	}
}



#endif // RUNNING_H
