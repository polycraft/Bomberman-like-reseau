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

            eventMove(event,tmpX,tmpY);

            int x=tmpX;x=x/10-1;
            int y=tmpY;y=y/10-1;

            if(event.keyState[SDLK_SPACE] && collision->detect(T_Bomberman,x,y)==C_Nothing)
            {
                this->gameType->getGame()->getMap()->addObject(new Bomb(this->gameType,this->gameType->getPlayer()->getId(), 2000, 2, 2),x,y,T_Dyn);
            }

            if(collision->detect(T_Bomberman,x,y)==C_Kill)
            {
                //Mort!
                this->gameType->getPlayer()->setVisible(false);
            }
		}

		void Running::eventMove(Engine::stateEvent &event,double tmpX,double tmpY)
		{
			//Met le bomber an position attente
			this->gameType->getPlayer()->setPause();

		    double vitesse=0.05*Timer::getTimePerFrame();
		    double distance=3.75;

            double xMin=(tmpX-vitesse-distance);
            double yMin=(tmpY-vitesse-distance);
            double xMax=(tmpX-vitesse+distance);
            double yMax=(tmpY-vitesse+distance);

            double rotate=0;
            int nbRotate=0;

            if(event.keyState[SDLK_LEFT])
            {
				//Met le bomber an position courir
				this->gameType->getPlayer()->setRunning();

                int point[4]={xMin-0.3,xMax,yMin,yMax};
                point[0]=point[0]/10-1;
                point[2]=point[2]/10-1;
                point[3]=point[3]/10-1;

                int position=tmpX;
                position=position/10-1;

                if(position==point[0] || collision->detect(T_Bomberman,point[0],point[2])!=C_Block && collision->detect(T_Bomberman,point[0],point[3])!=C_Block)
                {
                    this->gameType->getPlayer()->translation(-vitesse,0,0);
                }
                rotate+=180;
                nbRotate++;
            }

            if(event.keyState[SDLK_RIGHT])
            {
				//Met le bomber an position courir
				this->gameType->getPlayer()->setRunning();

                int point[4]={xMin,xMax+0.3,yMin,yMax};
                point[1]=point[1]/10-1;
                point[2]=point[2]/10-1;
                point[3]=point[3]/10-1;

                int position=tmpX;
                position=position/10-1;

                if(position==point[1] || collision->detect(T_Bomberman,point[1],point[2])!=C_Block && collision->detect(T_Bomberman,point[1],point[3])!=C_Block)
                {
                    this->gameType->getPlayer()->translation(vitesse,0,0);
                }
                nbRotate++;
            }
            if(event.keyState[SDLK_UP])
            {
				//Met le bomber an position courir
				this->gameType->getPlayer()->setRunning();

				int point[4]={xMin,xMax,yMin,yMax+0.3};
                point[0]=point[0]/10-1;
                point[1]=point[1]/10-1;
                point[3]=point[3]/10-1;

                int position=tmpY;
                position=position/10-1;

                if(position==point[3] || collision->detect(T_Bomberman,point[0],point[3])!=C_Block && collision->detect(T_Bomberman,point[1],point[3])!=C_Block)
                {
                    this->gameType->getPlayer()->translation(0,vitesse,0);
                }
                rotate+=90;
                nbRotate++;

            }
            if(event.keyState[SDLK_DOWN])
            {
 				//Met le bomber an position courir
				this->gameType->getPlayer()->setRunning();

				int point[4]={xMin,xMax,yMin-0.3,yMax};
                point[0]=point[0]/10-1;
                point[1]=point[1]/10-1;
                point[2]=point[2]/10-1;

                int position=tmpY;
                position=position/10-1;

                if(position==point[2] || collision->detect(T_Bomberman,point[0],point[2])!=C_Block && collision->detect(T_Bomberman,point[1],point[2])!=C_Block)
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

