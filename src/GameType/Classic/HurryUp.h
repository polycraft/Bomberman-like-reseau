#ifndef HURRYUP_H
#define HURRYUP_H

#include "Running.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		class HurryUp : public Running
		{

		public:
			HurryUp(GameType *gameType,CollisionDetector *collision);
			virtual ~HurryUp();
			void run();
			void updateTimer();
            void executeAction(const Engine::stateEvent &event);
		private:

		};
	}
}



#endif // HURRYUP_H
