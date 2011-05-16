#include "HurryUp.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		HurryUp::HurryUp(GameTypeSpace::Classic *gameType,CollisionDetector *collision)  : Running(gameType,collision)
		{
		}

		HurryUp::~HurryUp()
		{
		}


		void HurryUp::run()
		{
		}

		void HurryUp::updateTimer(unsigned int delay)
		{
		}
	}
}
