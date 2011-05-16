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
		    double tmpX=this->gameType->getPlayer()->getTransX();
		    double tmpY=this->gameType->getPlayer()->getTransY();

            int xMin=(tmpX-0.5-3.75);
            xMin/=10;
            xMin--;

            int yMin=(tmpY-0.5-3.75);
            yMin/=10;
            yMin--;

            int xMax=(tmpX-0.5+3.75);
            xMax/=10;
            xMax--;

            int yMax=(tmpY-0.5+3.75);
            yMax/=10;
            yMax--;

            if(event.keyState[SDLK_LEFT] && collision->detect(T_Bomberman,xMin,yMin)!=C_Block && collision->detect(T_Bomberman,xMin,yMax)!=C_Block)
            {
                this->gameType->getPlayer()->translation(-0.5,0,0);
                this->gameType->getPlayer()->setRotation(0,0,180);
            }
            if(event.keyState[SDLK_RIGHT] && collision->detect(T_Bomberman,xMax,yMin)!=C_Block && collision->detect(T_Bomberman,xMax,yMax)!=C_Block)
            {
                this->gameType->getPlayer()->translation(0.5,0,0);
                this->gameType->getPlayer()->setRotation(0,0,0);
            }
            if(event.keyState[SDLK_UP]&& collision->detect(T_Bomberman,xMin,yMax)!=C_Block && collision->detect(T_Bomberman,xMax,yMax)!=C_Block)
            {
                this->gameType->getPlayer()->translation(0,0.5,0);
                this->gameType->getPlayer()->setRotation(0,0,90);
            }
            if(event.keyState[SDLK_DOWN]&& collision->detect(T_Bomberman,xMin,yMin)!=C_Block && collision->detect(T_Bomberman,xMax,yMin)!=C_Block)
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

