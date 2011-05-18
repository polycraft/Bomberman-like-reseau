#include "Game.h"

#include "GameType/Classic/Classic.h"

Game::Game()
{
    engine =  new MainEngine();
	map = ManagerRessource::getRessource<Map>("src/ressource/map/test.map");

	Engine::Camera *camera = new Engine::Camera(map->getWidth()*10/2, 0, 150, map->getWidth()*10/2, map->getHeight()*10, 0, 0, 0, 1);
	engine->getGengine()->addCamera(camera);


	map->setEngine(engine);

	GameType *gameType=new GameTypeSpace::Classic(this);

    bool continuer=true;

	while(continuer)
	{
        //cout << "fps:" << Timer::getTimePerFrame() << endl;

        gameType->update();
        continuer=engine->run(camera);
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
