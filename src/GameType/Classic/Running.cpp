#include "Running.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		Running::Running(GameTypeSpace::Classic *gameType,CollisionDetector *collision)  : PhaseClassic(gameType,collision)
		{
		}

		Running::~Running()
		{
		}

		void Running::init()
		{
		}

		void Running::run()
		{
		}

		void Running::updateTimer()
		{
		}

		void Running::executeAction(const Engine::stateEvent &event)
		{

		}

		void Running::updateRecv(Socket *,const char*,int size)
		{

		}
	}
}

