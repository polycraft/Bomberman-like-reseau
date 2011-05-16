#include "Game.h"

#include "GameType/Classic/Classic.h"

Game::Game()
{
    engine =  new MainEngine();

    double place = 100;
	Engine::Camera *camera = new Engine::Camera(place, 0, 150, place, 100, 0, 0, 0, 1);
	engine->getGengine()->addCamera(camera);

	map = ManagerRessource::getRessource<Map>("src/ressource/map/test.map");

	map->setEngine(engine);

	GameType *gameType=new GameTypeSpace::Classic(this);

	while(engine->run(camera))
	{
        gameType->update();
	}
}

Game::~Game()
{
    //dtor
}

void Game::updateTimer(unsigned int delay)
{

}

Map *Game::getMap()
{
    return map;
}

MainEngine* Game::getEngine()
{
    return engine;
}
