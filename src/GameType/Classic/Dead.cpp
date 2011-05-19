#include "Dead.h"

#include "../../Map.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		Dead::Dead(GameTypeSpace::Classic *gameType,CollisionDetector *collision)  : PhaseClassic(gameType,collision)
		{
		}

		Dead::~Dead()
		{
		}

		void Dead::init()
		{
            this->gameType->getPlayer()->setVisible(false);
            this->nextEtat();
		}

		void Dead::run()
		{

		}

		void Dead::executeAction(Engine::stateEvent &event)
		{

		}

		void Dead::updateRecv(Socket *socket,const char*s,int size)
		{

		}
	}
}
