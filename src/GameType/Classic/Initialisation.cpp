#include "Initialisation.h"

#include "../../Map.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		Initialisation::Initialisation(GameTypeSpace::Classic *gameType,CollisionDetector *collision)  : PhaseClassic(gameType,collision)
		{
		}

		Initialisation::~Initialisation()
		{
		}

		void Initialisation::init()
		{
            this->nextEtat();
		}

		void Initialisation::run()
		{
		    Map *map=gameType->getGame()->getMap();

		    //Création du bomberman
		    Bomberman *bomber=new Bomberman(0);
		    bomber->setProperty<int>(PB_bombPower,2);
		    bomber->setProperty<double>(PB_vitesse,0.05);
		    bomber->setProperty<int>(PB_nbBomb,2);
		    bomber->setProperty<int>(PB_nbBombMax,2);
		    bomber->setProperty<int>(PB_timerBomb,2000);
		    bomber->setProperty<int>(PB_timerPutBomb,200);
		    bomber->setProperty<int>(PB_vitesseExplode,2);
		    bomber->setProperty<int>(PB_life,2);
		    bomber->setProperty<bool>(PB_canPutBomb,true);
		    bomber->setProperty<int>(PB_timeInvinsible,2000);
		    bomber->setProperty<bool>(PB_invinsible,false);
		    bomber->setInvinsible(5000);
		    bomber->setName("Test");
		    this->gameType->getFont().addText(bomber->getName());


		    this->gameType->setPlayer(bomber);
		    map->addBomberman(bomber,map->getSpawn(0));

            bomber=new Bomberman(1);
		    this->gameType->getPlayerNetwork().push_back(bomber);
		    map->addBomberman(bomber,map->getSpawn(1));

		    end(P_Next);
		}

		void Initialisation::executeAction(Engine::stateEvent &event)
		{

		}

		void Initialisation::updateRecv(Socket *socket,const char*s,int size)
		{

		}
	}
}
