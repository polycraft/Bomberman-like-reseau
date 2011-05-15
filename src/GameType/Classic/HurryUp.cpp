#include "HurryUp.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		HurryUp::HurryUp(GameType *gameType,CollisionDetector *collision)  : Running(gameType,collision)
		{
		}

		HurryUp::~HurryUp()
		{
		}


		void HurryUp::run()
		{
		}

		void HurryUp::updateTimer()
		{
		}

		void HurryUp::executeAction(const Engine::stateEvent &event)
		{

		}
	}
}
