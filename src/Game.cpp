#include "Game.h"

#include "Map.h"
#include "GameType/Classic/Classic.h"
#include <sstream>
#include <cmath>
#include "Loader/LoaderMap.h"
#include "Engine/ManagerRessource.h"
#include "network/SocketBomber.h"

using namespace Engine;

Game::Game()
{
    char nameBomber[]="Saucisse";

    engine =  new MainEngine(Engine_Graphic|Engine_Event);
    Loader *loaderMap=new LoaderMap();
    ManagerRessource::addLoader("map",loaderMap);

    preload();


	bool stop=false;

	//creation du socket vers le serveur
	Engine::Socket *socket= new SocketBomber("127.0.0.1",5001);

	//demande de connexion
	socket->setIsSync(true);

	Thread *thread=socket->run(&stop);



	//synchronisation du Timer
	int holdTime = Engine::Timer::getTimer()->getTime();
	PaquetPing askTime={'g', holdTime};
	socket->sendData<PaquetPing>(&askTime);
	Paquet paquet=socket->recvDataSync();
	PaquetPing *paquetTimer=paquet.getData<PaquetPing*>();
	int newTime = Engine::Timer::getTimer()->getTime();
	//Synchronisation
	int elapsedTime = (newTime-holdTime)/2;
	Engine::Timer::getTimer()->setTime(paquetTimer->timePaquet + elapsedTime);

	//demande de la map
	PaquetAsk askMap={'a', Engine::Timer::getTimer()->getTime(),'c'};//c = PaquetMap
	socket->sendData<PaquetAsk>(&askMap);
	//reception de la map

    paquet=socket->recvDataSync();
	PaquetMap *paquetMap=paquet.getData<PaquetMap*>();
	string path = "src/ressource/map/" + (string)paquetMap->name + ".map";
	cout << path << endl;
	map = ManagerRessource::getRessource<Map>(path);
	//map->buildMap();

	//Envoie du pseudo
	PaquetName paquetName={'n', Engine::Timer::getTimer()->getTime(),""};//c = PaquetMap
	strcpy(paquetName.name,nameBomber);
	socket->sendData<PaquetName>(&paquetName);

	//demande d'un identifiant
    PaquetAsk askId={'a', Engine::Timer::getTimer()->getTime(),'i'};
    socket->sendData<PaquetAsk>(&askId);
	//reception de l'id
	paquet=socket->recvDataSync();
    PaquetId *idAccptConnect=paquet.getData<PaquetId*>();
	if(idAccptConnect->id == -1){stop=true;}
	socket->setIsSync(false);


	Engine::Camera *camera = new Engine::Camera(map->getWidth()*10/2, 0, 150, map->getWidth()*10/2, map->getHeight()*10, 0, 0, 0, 1);
	engine->getGengine()->addCamera(camera);

	ManagerFont* font=new ManagerFont("src/ressource/font/font.ttf",12);
	string s("0");
	Text text(s,20,550);
	text.setColor(255,255,255,255);
	font->addText(&text);

	engine->getGengine()->getManagerText().addFont(font);

	map->setEngine(engine);

	GameTypeSpace::Classic *gameType=new GameTypeSpace::Classic(this, socket, idAccptConnect->id);

	socket->addObserverRecv(gameType);
	socket->addObserverRecv(this);
	cout << sizeof(int) << endl;
    std::stringstream out;
	while(!stop)
	{
        //cout << "fps:" << Timer::getTimePerFrame() << endl;

        gameType->update();
        stop=!(engine->run(camera));

        std::stringstream out;
        out << static_cast<int>(1000/Timer::getTimer()->getTimePerFrame());
        s=out.str();
        text.setText(s);
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

void Game::preload()
{
    ManagerRessource::getRessource("src/ressource/object/bomb.obj");
    ManagerRessource::getRessource("src/ressource/texture/bomb.jpg");

    ManagerRessource::getRessource("src/ressource/object/bombermanPause.obj");
    ManagerRessource::getRessource("src/ressource/texture/bomberman.jpg");
    ManagerRessource::getRessource("src/ressource/object/bombermanRun.obj");

    ManagerRessource::getRessource("src/ressource/object/bonus.obj");
	ManagerRessource::getRessource("src/ressource/texture/bonus/bonusFaster.png");

	ManagerRessource::getRessource("src/ressource/object/bonus.obj");
	ManagerRessource::getRessource("src/ressource/texture/bonus/bonusBomb.png");

	ManagerRessource::getRessource("src/ressource/object/bonus.obj");
	ManagerRessource::getRessource("src/ressource/texture/bonus/bonusPower.png");

	ManagerRessource::getRessource("src/ressource/texture/box2.jpg");

	ManagerRessource::getRessource("src/ressource/object/bodyExplosion.obj");
    ManagerRessource::getRessource("src/ressource/texture/bodyExplosion.png");

    ManagerRessource::getRessource("src/ressource/texture/steel2.jpg");
}
