#include "Initialisation.h"

#include "Classic.h"
#include "../../Map.h"
#include "../../Type/Bomberman.h"
#include "../../Game.h"


using namespace Engine;

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		Initialisation::Initialisation(GameTypeSpace::Classic *gameType,CollisionDetector *collision, int idBomber)  : PhaseClassic(gameType,collision)
		{
			this->idBomber = idBomber;
		}

		Initialisation::~Initialisation()
		{
		}

		void Initialisation::init()
		{
			//reconstruction de map au changement de round
			//ajout de tout les bomberman sur la map
			Map *map=gameType->getGame()->getMap();

		    //Création du bomberman
			Bomberman *bomber=new Bomberman(this->idBomber);
		    bomber->setProperty<int>(PB_bombPower,2);
		    bomber->setProperty<double>(PB_speed,0.05);
		    bomber->setProperty<int>(PB_nbBomb,2);
		   // bomber->setProperty<int>(PB_nbBombMax,2);
		    bomber->setProperty<int>(PB_timerBomb,2000);
		    bomber->setProperty<int>(PB_timerPutBomb,200);
		    bomber->setProperty<int>(PB_speedExplode,2);
		    bomber->setProperty<int>(PB_life,2);
		    bomber->setProperty<bool>(PB_canPutBomb,true);
		    bomber->setProperty<int>(PB_timeInvincible,2000);
		    bomber->setProperty<bool>(PB_invincible,false);
		    bomber->setInvincible(5000);
		    bomber->setName("Test");
		    this->gameType->getFont().addText(bomber->getName());


		    this->gameType->setPlayer(bomber);
		    map->addBomberman(bomber,map->getSpawn(0));

            bomber=new Bomberman(1);
		    this->gameType->getPlayerNetwork().push_back(bomber);
		    map->addBomberman(bomber,map->getSpawn(1));


			this->nextEtat();
		}

		void Initialisation::run()
		{
		    

		}

		void Initialisation::executeAction(Engine::stateEvent &event)
		{

		}

		void Initialisation::updateRecv(Socket *socket,Paquet& paquet)
		{
			char type=(paquet.getData())[0];
			switch(type)
			{
				case 's'://Spawn
				{
					PaquetSpawn *paquetSpawn=paquet.getData<PaquetSpawn*>();
					Bomberman *bomber = new Bomberman(paquetSpawn->idBomber);
					this->gameType->getGame()->getMap()->addBomberman(bomber,this->gameType->getGame()->getMap()->getSpawn(paquetSpawn->idSpawn));
				}
			}
		}
	}
}
