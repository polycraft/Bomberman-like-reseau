#include "HurryUp.h"
#include "Classic.h"
#include "../../Map.h"
#include "../../Game.h"
#include "../../Type/StaticBloc.h"
#include "../../Type/Explosion.h"
#include "../../Type/ExplosionFlare.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		HurryUp::HurryUp(GameTypeSpace::Classic *gameType,CollisionDetector *collision)  : Running(gameType,collision)
		{
			this->blocDown = false;
			this->actuTime = 10;
			this->blocx = 0;
			this->blocy = 0;
			this->blocz = 50;
			this->direction = D_Haut;
			this->nbIteration = 0;
			this->countIteration = 1;
			this->nbFailure=0;
			this->bloc = NULL;
		}

		HurryUp::~HurryUp()
		{

		}

		void HurryUp::init()
		{
			this->bloc = new StaticBloc();
			this->gameType->getGame()->getMap()->addObjectToScene(this->bloc,this->blocx,this->blocy, this->blocz, T_Dyn);
			this->nextEtat();
		}
		void HurryUp::run()
		{
			
		}

		void HurryUp::updateTimer(unsigned int delay)
		{
			if(delay == this->actuTime)
			{
				if(blocz>=0)
					{
						this->bloc->setCoordonnes(this->blocx*10+15,this->blocy*10+15,this->blocz+5);
						this->blocz -= Engine::Timer::getTimer()->getTimePerFrame()/4;
					}
				else
				{
					//this->bloc->destroy();
					Engine::Timer::getTimer()->removeListener(this,this->actuTime);
				}
			}
		}

		void HurryUp::updateRecv(Engine::Socket * socket,Engine::Paquet& paquet)
		{
			char type=(paquet.getData())[0];
			switch(type)
			{
				case 'h'://HurryBloc
				{
					
					if(!this->blocDown)
					{
						
						EType type;
						if(this->gameType->getGame()->getMap()->get(this->blocx,this->blocy) != NULL)
						{
							type = this->gameType->getGame()->getMap()->get(this->blocx,this->blocy)->getType();
							if(type == T_BreakableBloc || type == T_Bonus)
							{
								this->gameType->getGame()->getMap()->addObject(new StaticBloc(), this->blocx, this->blocy, T_Dyn);
								//Engine::Timer::getTimer()->removeListener(this,this->actuTime);

							}
							else if( type == T_Bomb)
							{
								this->gameType->getGame()->getMap()->addObject(new StaticBloc(), this->blocx, this->blocy, T_Dyn);
								this->gameType->getPlayer()->setProperty<int>(PB_nbBomb, this->gameType->getPlayer()->getProperty<int>(PB_nbBomb)+1);
								//Engine::Timer::getTimer()->removeListener(this,this->actuTime);
							}
							else if(type == T_Explosion)
							{
								Explosion* explosion = dynamic_cast<Explosion*>(this->gameType->getGame()->getMap()->get(this->blocx,this->blocy));
								explosion->getExplosionFlare()->removeExplosion(explosion);
								this->gameType->getGame()->getMap()->addObject(new StaticBloc(), this->blocx, this->blocy, T_Dyn);
								//Engine::Timer::getTimer()->removeListener(this,this->actuTime);

							}
						}
						else
						{
							this->gameType->getGame()->getMap()->addObject(new StaticBloc(), this->blocx, this->blocy, T_Dyn);
							//Engine::Timer::getTimer()->removeListener(this,this->actuTime);
		
						}
					}

					Engine::Timer::getTimer()->addListener(this,this->actuTime);
					PaquetHurry *paquetHurry=paquet.getData<PaquetHurry*>();
					this->blocx = paquetHurry->x;
					this->blocy = paquetHurry->y;
					this->blocz = 50;
					this->blocDown = false;
				}
				break;
			}
			
			Running::updateRecv(socket, paquet);

		}

	}
}
