#ifndef INITIALISATION_H
#define INITIALISATION_H

#include "PhaseClassic.h"
#include "Classic.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		class Initialisation : public PhaseClassic
		{

		public:
			Initialisation(GameTypeSpace::Classic *gameType,CollisionDetector *collision);
			virtual ~Initialisation();
			void init();
			void run();
            void executeAction(Engine::stateEvent &event);
            virtual void updateRecv(Socket *,const char*,int size);
		};
	}
}



#endif // INITIALISATION_H
