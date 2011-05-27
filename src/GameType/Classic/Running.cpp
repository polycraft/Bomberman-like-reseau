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

            if(event.keyState[SDLK_SPACE] && collision->detect(T_Bomberman,x,y)==C_Nothing && this->gameType->getPlayer()->getProperty<int>(PB_nbBomb)>0 &&
               this->gameType->getPlayer()->getProperty<bool>(PB_canPutBomb))
            {
                Bomberman* bomber=this->gameType->getPlayer();
				
                Bomb* bomb=new Bomb(
                                    this->gameType,
                                    bomber->getProperty<int>(PB_id),
                                    bomber->getProperty<int>(PB_timerBomb),
                                    bomber->getProperty<int>(PB_vitesseExplode),
                                    bomber->getProperty<int>(PB_bombPower));
                this->gameType->getGame()->getMap()->addObject(bomb,x,y,T_Dyn);

                bomber->setProperty<int>(PB_nbBomb,bomber->getProperty<int>(PB_nbBomb)-1);
                bomber->setProperty<bool>(PB_canPutBomb,false);
                Timer::getTimer()->addListenerOnce(bomber,bomber->getProperty<int>(PB_timerPutBomb));
            }

            if(collision->detect(T_Bomberman,x,y)==C_Kill && this->gameType->getPlayer()->getProperty<bool>(PB_invinsible)==false)
            {

                //Mort!
                this->gameType->getPlayer()->lostLife();


                if(this->gameType->getPlayer()->getProperty<int>(PB_life)<=0)
                {
                    end(P_Next);
                }
                else
                {
                    this->gameType->getPlayer()->setInvinsible(5000);
                }


            }

			if(collision->detect(T_Bomberman,x,y)==C_Bonus)
            {
				Bonus *bonus = dynamic_cast<Bonus*>(this->gameType->getGame()->getMap()->get(x,y));
				Bomberman *bomber=this->gameType->getPlayer();
				//Active l'effet du bonus:
				bonus->getEffect()->enableEffect(bomber);
                //Ajoute le bonus au bomberman
				bomber->addBonus(bonus);
				//fait disparaitre le bonus
				bonus->setVisible(false);
				this->gameType->getGame()->getMap()->set(NULL,x,y);


            }
		}

		void Running::eventMove(Engine::stateEvent &event,double tmpX,double tmpY)
		{
			//Met le bomber an position attente
			this->gameType->getPlayer()->setPause();

		    double vitesse=this->gameType->getPlayer()->getProperty<double>(PB_vitesse)*Timer::getTimePerFrame();
		    if(vitesse>8)
		    {
		        vitesse=8;
		    }
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

                int point[4]={xMin-vitesse,xMax,yMin,yMax};
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

                int point[4]={xMin,xMax+vitesse,yMin,yMax};
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

				int point[4]={xMin,xMax,yMin,yMax+vitesse};
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

				int point[4]={xMin,xMax,yMin-vitesse,yMax};
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

		void Running::updateRecv(Socket *socket,Paquet& paquet)
		{

		}
	}
}

