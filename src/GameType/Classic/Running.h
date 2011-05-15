#ifndef RUNNING_H
#define RUNNING_H

#include "../Phase.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		class Running : public Phase
		{

		public:
			Running(GameType *gameType,CollisionDetector *collision);
			virtual ~Running();
			void init();
			virtual void run();
			virtual void updateTimer();
            void executeAction(const Engine::stateEvent &event);
		private:

		};
	}
}



#endif // RUNNING_H
