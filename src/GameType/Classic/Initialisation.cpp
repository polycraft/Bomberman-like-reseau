#include "Initialisation.h"

#include "../../Map.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
		Initialisation::Initialisation(GameTypeSpace::Classic *gameType,CollisionDetector *collision)  : gameType(gameType),Phase(collision)
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
		    SCoordinate coord=map->getSpawn(0);
		    Bomberman *bomber=new Bomberman(0,map->getSpawn(0));
		    this->gameType->setPlayer(bomber);
		    map->addBomberman(bomber);

            bomber=new Bomberman(1,map->getSpawn(1));
		    this->gameType->getPlayerNetwork().push_back(bomber);
		    map->addBomberman(bomber);
		}

		void Initialisation::executeAction(const Engine::stateEvent &event)
		{

		}
	}
}
