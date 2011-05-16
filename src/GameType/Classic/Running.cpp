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
		    this->nextEtat();
		}

		void Running::run()
		{

		}

		void Running::updateTimer()
		{
		}

		void Running::executeAction(Engine::stateEvent &event)
		{
            if(event.keyState[SDLK_LEFT])
            {
                this->gameType->getPlayer()->translation(-0.5,0,0);
                this->gameType->getPlayer()->setRotation(0,0,180);
            }
            if(event.keyState[SDLK_RIGHT])
            {
                this->gameType->getPlayer()->translation(0.5,0,0);
                this->gameType->getPlayer()->setRotation(0,0,0);
            }
            if(event.keyState[SDLK_UP])
            {
                this->gameType->getPlayer()->translation(0,0.5,0);
                this->gameType->getPlayer()->setRotation(0,0,90);
            }
            if(event.keyState[SDLK_DOWN])
            {
                this->gameType->getPlayer()->translation(0,-0.5,0);
                this->gameType->getPlayer()->setRotation(0,0,-90);
            }
		}

		void Running::updateRecv(Socket *socket,const char*s,int size)
		{

		}
	}
}

