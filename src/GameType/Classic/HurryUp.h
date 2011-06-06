#ifndef HURRYUP_H
#define HURRYUP_H

#include "Running.h"
#include "../../Engine/util/IObserverTimer.h"
#include "../../Type/StaticBloc.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		class HurryUp : public Running,public Engine::IObserverTimer
		{
			enum EDirection
			{
				D_Haut,
				D_Bas,
				D_Gauche,
				D_Droite
			};
		public:
			HurryUp(GameTypeSpace::Classic *gameType,CollisionDetector *collision);
			virtual ~HurryUp();
			void init();
			void run();
			void updateTimer(unsigned int delay);
		private:
			int timeBetweenBloc;
			int actuTime;
			int blocx;
			int blocy;
			double blocz;
			int nbIteration;
			int countIteration;
			int nbFailure;//detection de la fin du hurryUp/recouvrement total
			EDirection direction;
			StaticBloc *bloc;
		};
	}
}



#endif // HURRYUP_H
