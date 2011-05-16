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
