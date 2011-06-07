#include "HurryUp.h"
#include "Classic.h"
#include "../../Map.h"
#include "../../Game.h"



namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		HurryUp::HurryUp(GameTypeSpace::Classic *gameType,CollisionDetector *collision)  : Running(gameType,collision)
		{
			this->timeBetweenBloc = 1000;//inutilisé
			this->actuTime = 50;
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
			Engine::Timer::getTimer()->addListener(this,this->actuTime);
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
						this->blocz -= 3;
					}
				else
				{
						this->blocz = 50;
						EType type;
						if(this->gameType->getGame()->getMap()->get(this->blocx,this->blocy) != NULL)
						{
							type = this->gameType->getGame()->getMap()->get(this->blocx,this->blocy)->getType();
						}
				
						if(this->gameType->getGame()->getMap()->get(this->blocx,this->blocy) == NULL  || type == T_BreakableBloc || type == T_Bonus)
						{
							this->gameType->getGame()->getMap()->addObject(new StaticBloc(), this->blocx, this->blocy, T_Dyn);
						}
						else if( type == T_Bomb)
						{
							this->gameType->getGame()->getMap()->addObject(new StaticBloc(), this->blocx, this->blocy, T_Dyn);
							this->gameType->getPlayer()->setProperty<int>(PB_nbBomb, this->gameType->getPlayer()->getProperty<int>(PB_nbBomb)+1);
						}
						switch(this->direction)
						{
							case D_Haut:

								if(this->blocy >= this->gameType->getGame()->getMap()->getHeight()-1 - nbIteration)//verif changement de direction
								{
									this->direction = D_Droite;
									this->countIteration++;
									nbFailure++;
								}
								else
								{
									this->blocy++;//ajoute en hauteur
									nbFailure = 0;
								}
								if(countIteration >=2)
								{
									nbIteration++;//enleve un bloc au bout de 2 ligne/colonnes
									countIteration = 0;
								}
						

							break;

							case D_Bas:
								if(this->blocy <= -1 + nbIteration)//verif changement de direction
								{
							
									this->direction = D_Gauche;
									this->countIteration++;
									nbFailure++;
								}
								else
								{
									this->blocy--;//ajoute en hauteur
									nbFailure = 0;
								}
								if(countIteration >=2)
								{
									nbIteration++;//enleve un bloc au bout de 2 ligne/colonnes
									countIteration = 0;
								}

							break;

							case D_Droite:
								if(this->blocx > this->gameType->getGame()->getMap()->getWidth()-1 - nbIteration)//verif changemant de direction
								{
									this->direction = D_Bas;
									this->countIteration++;
									nbFailure++;
								}
								else
								{
									this->blocx++;//ajoute en hauteur
									nbFailure = 0;
								}
								if(countIteration >=2)
								{
									nbIteration++;//enleve un bloc au bout de 2 ligne/colonnes
									countIteration = 0;
								}

							break;
							case D_Gauche:
								if(this->blocx <= -1+ nbIteration)//verif changemant de direction
								{
									cout << nbFailure << endl;
									this->direction = D_Haut;
									this->nbIteration -=1;//important sinon difference de 1carré a chaque tours
									this->countIteration++;
									nbFailure++;
									if(nbFailure >=2)
									{
										//on stoppe le timer
										Engine::Timer::getTimer()->removeListener(this,this->actuTime);
									}

								}
								else
								{
									this->blocx--;//ajoute en hauteur
									nbFailure = 0;
								}
								if(countIteration >=2)
								{
									nbIteration++;//enleve un bloc au bout de 2 ligne/colonnes
									countIteration = 0;
								}
								break;
	
							}
				/*this->blocz = 20;
				Engine::Timer::getTimer()->addListener(this,this->actuTime);
				this->bloc = new StaticBloc();
				this->gameType->getGame()->getMap()->addObjectToScene(this->bloc,this->blocx,this->blocy, this->blocz, T_Dyn);*/

				}


			}
		}
	}
}
