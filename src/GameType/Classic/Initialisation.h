#ifndef INITIALISATION_H
#define INITIALISATION_H

#include "PhaseClassic.h"

namespace GameTypeSpace
{
    class Classic;
}
class CollisionDetector;


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
            virtual void updateRecv(Engine::Socket *,Engine::Paquet& paquet);
		};
	}
}



#endif // INITIALISATION_H
