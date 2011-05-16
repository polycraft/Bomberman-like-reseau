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

		void Running::updateTimer(unsigned int delay)
		{
		}

		void Running::executeAction(Engine::stateEvent &event)
		{
		    int tmpX=this->gameType->getPlayer()->getTransX();
		    int tmpY=this->gameType->getPlayer()->getTransY();
		    int width=this->gameType->getGame()->getMap()->getWidth();
		    int height=this->gameType->getGame()->getMap()->getLength();



            if(event.keyState[SDLK_LEFT] && collision->detect(T_Bomberman,(tmpX-0.5)/width,tmpY/height)!=C_Block)
            {
                this->gameType->getPlayer()->translation(-0.5,0,0);
                this->gameType->getPlayer()->setRotation(0,0,180);
            }
            if(event.keyState[SDLK_RIGHT] && tmpX+5+5<width*10)
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

