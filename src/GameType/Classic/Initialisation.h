#ifndef INITIALISATION_H
#define INITIALISATION_H

#include "../Phase.h"
#include "Classic.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		class Initialisation : public Phase
		{

		public:
			Initialisation(GameTypeSpace::Classic *gameType,CollisionDetector *collision);
			virtual ~Initialisation();
			void init();
			void run();
            void executeAction(const Engine::stateEvent &event);
		private:
            Classic *gameType;
		};
	}
}



#endif // INITIALISATION_H
