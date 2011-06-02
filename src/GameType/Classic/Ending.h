#ifndef ENDING_H
#define ENDING_H

#include "Running.h"
#include "../../Engine/util/IObserverTimer.h"

class IObserverTimer;

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		class Ending : public Running, Engine::IObserverTimer
		{

		public:
			Ending(GameTypeSpace::Classic *gameType,CollisionDetector *collision);
			virtual ~Ending();
			void init();
			void run();
			void updateTimer(unsigned int delay);
		private:
			int waitTime;
		};
	}
}



#endif // ENDING_H