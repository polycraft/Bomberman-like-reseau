#ifndef ENDING_H
#define ENDING_H

#include "Running.h"
#include "../../Engine/util/IObserverTimer.h"

class IObserverTimer;

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		class Ending : public PhaseClassic, Engine::IObserverTimer
		{

		public:
			Ending(GameTypeSpace::Classic *gameType,CollisionDetector *collision);
			virtual ~Ending();
			void init();
			void run();
			void updateTimer(unsigned int delay);
			void executeAction(Engine::stateEvent &event);
			void updateRecv(Engine::Socket *,Engine::Paquet& paquet);
		private:
			int waitTime;
		};
	}
}



#endif // ENDING_H
