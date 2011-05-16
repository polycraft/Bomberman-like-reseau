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

		    double vitesse=0.1;
		    double distance=3.75;

            double xMin=(tmpX-vitesse-distance);
            double yMin=(tmpY-vitesse-distance);
            double xMax=(tmpX-vitesse+distance);
            double yMax=(tmpY-vitesse+distance);

            double rotate=0;
            int nbRotate=0;

            if(event.keyState[SDLK_LEFT])
            {
                int point[4]={xMin-0.1,xMax,yMin,yMax};
                point[0]=point[0]/10-1;
                point[2]=point[2]/10-1;
                point[3]=point[3]/10-1;

                if(collision->detect(T_Bomberman,point[0],point[2])!=C_Block && collision->detect(T_Bomberman,point[0],point[3])!=C_Block)
                {
                    this->gameType->getPlayer()->translation(-vitesse,0,0);
                }
                rotate+=180;
                nbRotate++;
            }

            if(event.keyState[SDLK_RIGHT])
            {
                int point[4]={xMin,xMax+0.1,yMin,yMax};
                point[1]=point[1]/10-1;
                point[2]=point[2]/10-1;
                point[3]=point[3]/10-1;
                if(collision->detect(T_Bomberman,point[1],point[2])!=C_Block && collision->detect(T_Bomberman,point[1],point[3])!=C_Block)
                {
                    this->gameType->getPlayer()->translation(vitesse,0,0);
                }
                nbRotate++;
            }
            if(event.keyState[SDLK_UP])
            {
                int point[4]={xMin,xMax,yMin,yMax+0.1};
                point[0]=point[0]/10-1;
                point[1]=point[1]/10-1;
                point[3]=point[3]/10-1;
                if(collision->detect(T_Bomberman,point[0],point[3])!=C_Block && collision->detect(T_Bomberman,point[1],point[3])!=C_Block)
                {
                    this->gameType->getPlayer()->translation(0,vitesse,0);
                }
                rotate+=90;
                nbRotate++;

            }
            if(event.keyState[SDLK_DOWN])
            {
                int point[4]={xMin,xMax,yMin-0.1,yMax};
                point[0]=point[0]/10-1;
                point[1]=point[1]/10-1;
                point[2]=point[2]/10-1;

                if(collision->detect(T_Bomberman,point[0],point[2])!=C_Block && collision->detect(T_Bomberman,point[1],point[2])!=C_Block)
                {
                    this->gameType->getPlayer()->translation(0,-vitesse,0);
                }
                if(rotate>=180)
                    rotate+=270;
                else
                    rotate-=90;
                nbRotate++;
            }

            if(nbRotate>=1)
                this->gameType->getPlayer()->setRotation(0,0,rotate/nbRotate);
		}

		void Running::updateRecv(Socket *socket,const char*s,int size)
		{

		}
	}
}

