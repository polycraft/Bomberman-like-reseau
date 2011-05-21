#include "Game.h"

#include "GameType/Classic/Classic.h"
#include <sstream>

Game::Game()
{
    engine =  new MainEngine();
	map = ManagerRessource::getRessource<Map>("src/ressource/map/test.map");

	Engine::Camera *camera = new Engine::Camera(map->getWidth()*10/2, 0, 150, map->getWidth()*10/2, map->getHeight()*10, 0, 0, 0, 1);
	engine->getGengine()->addCamera(camera);

	ManagerFont* font=new ManagerFont("src/ressource/font/font.ttf",24);
	string s("Blablbla");
	Text text(s,20,500);
	text.setColor(255,255,255,255);
	font->addText(&text);
	engine->getGengine()->getManagerText().addFont(font);

	map->setEngine(engine);

	GameType *gameType=new GameTypeSpace::Classic(this);


    bool continuer=true;

    std::stringstream out;

	while(continuer)
	{
        //cout << "fps:" << Timer::getTimePerFrame() << endl;

        gameType->update();
        continuer=engine->run(camera);

        std::stringstream out;
        out << static_cast<int>(1000/Timer::getTimePerFrame());
        s=out.str();
    text.setText(s);
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
