#include "testMap.h"


using namespace Engine;

int testMap()
{

	//creer une map de test
	creerMap("src/ressource/map/test.map");
	//

	MainEngine *engine =  new MainEngine();

			Texture *texture = ManagerRessource::getRessource<Texture>("src/ressource/texture/cube.png");
	GLuint notext= texture->getTexture();
	double place = 50;
	Engine::Camera *camera = new Engine::Camera(place, -50, 80, place, place, 0, 0, 0, 1);
	engine->getGengine()->addCamera(camera);

	Map *map = ManagerRessource::getRessource<Map>("src/ressource/map/test.map");

	map->setEngine(engine);
	



	int continuer = 1;
	SDL_Event event;

	while (continuer)
	{
		SDL_Delay(30);
		SDL_PollEvent(&event);

		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
				case SDL_KEYDOWN :
			switch (event.key.keysym.sym)
			{
				case SDLK_UP:
				break;
			}
		}
		engine->getGengine()->draw(camera);

	}
	return 0;
}

void creerMap(string name)
{
	struct SHeader test;

	test.gameType= T_Classic;
	test.height = 14;
	test.width = 8;

	
	ofstream mapFile(name.c_str(), ios::out | ios::binary);
	if(!mapFile)
	{
		throw new ExceptionNoFileFound();
	}

	mapFile.write((char *) &test, sizeof(struct SHeader));
	//cree le tableau de map
	char element[112] = {
	'a', '0', '0' , '0' ,'a', 'b', '0' , '0' ,
	'0', '0', 'a' , '0' ,'0', '0', 'a' , '0' ,
	'0', 'a', 'b' , 'a' ,'0', '0', 'a' , '0' ,
	'0', 'b', 'b' , 'b' ,'b', 'b', '0' , '0' ,
	'0', 'a', 'b' , 'a' ,'b', '0', '0' , '0' ,
	'0', 'b', '0' , '0' ,'0', 'b', 'b' , '0' ,
	'0', 'a', '0' , '0' ,'0', 'a', 'b' , '0' ,
	'0', '0', '0' , '0' ,'0', '0', '0' , '0' ,
	'0', '0', 'b' , '0' ,'0', '0', 'b' , '0' ,
	'0', '0', '0' , '0' ,'a', '0', '0' , '0' ,
	'0', '0', '0' , '0' ,'a', '0', '0' , '0' ,
	'0', '0', 'b' , '0' ,'0', '0', 'b' , '0' ,
	'0', '0', '0' , 'b' ,'b', 'b', '0' , '0' ,
	'0', '0', '0' , '0' ,'0', '0', '0' , '0' 
	};
	

	mapFile.write(element, sizeof(char)*test.height*test.width);

	mapFile.close();
}