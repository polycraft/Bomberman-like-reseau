#ifndef INITIALISATION_H
#define INITIALISATION_H

#include "../Phase.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		class Initialisation : public Phase
		{

		public:
			Initialisation(GameType *gameType,CollisionDetector *collision);
			virtual ~Initialisation();
			void init();
			void run();
            void executeAction(const Engine::stateEvent &event);
		private:

		};
	}
}



#endif // INITIALISATION_H
