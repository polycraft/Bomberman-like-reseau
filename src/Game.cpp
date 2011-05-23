#include "Game.h"

#include "GameType/Classic/Classic.h"
#include <sstream>
#include <cmath>
#include "Loader/LoaderMap.h"

Game::Game()
{
    engine =  new MainEngine();
    Loader *loaderMap=new LoaderMap();
    ManagerRessource::addLoader("map",loaderMap);

	map = ManagerRessource::getRessource<Map>("src/ressource/map/test.map");

	Engine::Camera *camera = new Engine::Camera(map->getWidth()*10/2, 0, 150, map->getWidth()*10/2, map->getHeight()*10, 0, 0, 0, 1);
	engine->getGengine()->addCamera(camera);

	ManagerFont* font=new ManagerFont("src/ressource/font/font.ttf",24);
	string s("0");
	Text text(s,20,500);


	/////////
	ManagerFont* font2=new ManagerFont("src/ressource/font/font.ttf",10);
	double tailleBomber = 10;
	double test = (map->getHeight()*10.0*10/150);
	Text text3d(s,0,0,-(map->getHeight()*10.0*10/150)*sqrt(150*150+map->getHeight()*map->getHeight()*100.0)/(map->getHeight()*10.0));
	///////
	text.setColor(255,255,255,255);
	text3d.setColor(255,255,255,255);
	font->addText(&text);
	font2->addText(&text3d);

	engine->getGengine()->getManagerText().addFont(font);
	engine->getGengine()->getManagerText().addFont(font2);

	map->setEngine(engine);

	GameTypeSpace::Classic *gameType=new GameTypeSpace::Classic(this);


    bool continuer=true;

    std::stringstream out;

	while(continuer)
	{
        //cout << "fps:" << Timer::getTimePerFrame() << endl;

        gameType->update();
        continuer=engine->run(camera);

		//Calculs de position du texte
		double b =(map->getHeight()*10.0);
		if(gameType->getPlayer()!=NULL)
		{
            double Y = 	gameType->getPlayer()->getTransY();
            double X = 	gameType->getPlayer()->getTransX();
            double H = sqrt(150*150+b*b);
            double I1 = 150*H/b;
            double I2 = 150*150/b;
            text3d.setCoord(X-map->getWidth()*10/2-10,10*H/b-I1*((b-Y)/(b+I2)),-H*(1-(b-Y)/(b+I2)));
            //

            text3d.setText("Bob");

            std::stringstream out;
            out << static_cast<int>(1000/Timer::getTimePerFrame());
            s=out.str();
            text.setText(s);
		}
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
