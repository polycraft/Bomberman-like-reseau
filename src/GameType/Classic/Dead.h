#ifndef DEAD_H
#define DEAD_H

#include "PhaseClassic.h"
#include "Classic.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		class Dead : public PhaseClassic
		{

		public:
			Dead(GameTypeSpace::Classic *gameType,CollisionDetector *collision);
			virtual ~Dead();
			void init();
			void run();
            void executeAction(Engine::stateEvent &event);
            virtual void updateRecv(Socket *,const char*,int size);
		};
	}
}


#endif // DEAD_H
