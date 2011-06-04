#include "Game.h"

#include "Map.h"
#include "GameType/Classic/Classic.h"
#include <sstream>
#include <cmath>
#include "Loader/LoaderMap.h"
#include "Engine/ManagerRessource.h"

using namespace Engine;

Game::Game()
{
    engine =  new MainEngine(Engine_Graphic|Engine_Event);
    Loader *loaderMap=new LoaderMap();
    ManagerRessource::addLoader("map",loaderMap);



ManagerRessource::getRessource("src/ressource/object/bomb.obj");
		ManagerRessource::getRessource("src/ressource/texture/bomb.jpg");


	bool stop=false;

	//creation du socket vers le serveur
	Engine::Socket *socket= new Engine::Socket("127.0.0.1",5001);
	Thread *thread=socket->run(&stop);


	//demande de connexion
	socket->setIsSync(true);
	//synchronisation du Timer
	int holdTime = Engine::Timer::getTimer()->getTime();
	PaquetPing askTime={'g', holdTime};
	socket->sendData<PaquetPing>(&askTime);
	PaquetPing *paquetTimer=(socket->recvData()).getData<PaquetPing*>();
	int newTime = Engine::Timer::getTimer()->getTime();
	//Synchronisation
	int elapsedTime = (newTime-holdTime)/2;
	Engine::Timer::getTimer()->setTime(paquetTimer->timePaquet + elapsedTime);

	//demande de la map
	PaquetAsk askMap={'a', Engine::Timer::getTimer()->getTime(),'c'};//c = PaquetMap
	socket->sendData<PaquetAsk>(&askMap);
	//reception de la map
	PaquetMap *paquetMap=(socket->recvData()).getData<PaquetMap*>();
	string path = "src/ressource/map/" + (string)paquetMap->name + ".map";
	map = ManagerRessource::getRessource<Map>(path);
	map->buildMap();
	//demande d'un identifiant
    PaquetAsk askId={'a', Engine::Timer::getTimer()->getTime(),'i'};
    socket->sendData<PaquetAsk>(&askId);
	//reception de l'id
    PaquetId *idAccptConnect=(socket->recvData()).getData<PaquetId*>();
	if(idAccptConnect->id == -1){stop=true;}
	socket->setIsSync(false);


	Engine::Camera *camera = new Engine::Camera(map->getWidth()*10/2, 0, 150, map->getWidth()*10/2, map->getHeight()*10, 0, 0, 0, 1);
	engine->getGengine()->addCamera(camera);

	ManagerFont* font=new ManagerFont("src/ressource/font/font.ttf",24);
	string s("0");
	Text text(s,20,500);


	/////////
	ManagerFont* font2=new ManagerFont("src/ressource/font/font.ttf",10);
	//double tailleBomber = 10;
	//double test = (map->getHeight()*10.0*10/150);
	Text text3d(s,0,0,-(map->getHeight()*10.0*10/150)*sqrt(150*150+map->getHeight()*map->getHeight()*100.0)/(map->getHeight()*10.0));
	///////
	text.setColor(255,255,255,255);
	text3d.setColor(255,255,255,255);
	font->addText(&text);
	font2->addText(&text3d);

	engine->getGengine()->getManagerText().addFont(font);
	engine->getGengine()->getManagerText().addFont(font2);

	map->setEngine(engine);

	GameTypeSpace::Classic *gameType=new GameTypeSpace::Classic(this, socket, idAccptConnect->id);

	socket->addObserverRecv(gameType);
	socket->addObserverRecv(this);

    std::stringstream out;

	while(!stop)
	{
        //cout << "fps:" << Timer::getTimePerFrame() << endl;

        gameType->update();
        stop=!(engine->run(camera));

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
            out << static_cast<int>(1000/Timer::getTimer()->getTimePerFrame());
            s=out.str();
            text.setText(s);
		}
	}
	Threadable::join(thread);
	delete socket;
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

void Game::updateRecv(Socket *sock,Paquet& paquet)
{

}
