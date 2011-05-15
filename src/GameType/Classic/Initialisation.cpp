#include "Initialisation.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		Initialisation::Initialisation(GameType *gameType,CollisionDetector *collision)  : Phase(gameType,collision)
		{
		}

		Initialisation::~Initialisation()
		{
		}

		void Initialisation::init()
		{
		}

		void Initialisation::run()
		{
		}

		void Initialisation::executeAction(const Engine::stateEvent &event)
		{

		}
	}
}
