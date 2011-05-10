#include "testGraphicEngine.h"
using namespace Engine;
int testGraphicEngine()
{
	GraphicEngine engine("TestGraphicEngine",800, 600,1,1);
	Camera *camera = new Camera(6, 0, 6, 0, 0, 0, 0, 0, 1);
	engine.addCamera(camera);

	Scene *scene1 = new Scene(Engine::TS_Static);
	engine.addScene(scene1);

	//test de texture
	Ressource *texture[4];
	texture[0] = ManagerRessource::getRessource("src/ressource/texture/box.jpg");
	texture[1] = ManagerRessource::getRessource("src/ressource/texture/bomb.jpg");
	texture[2] = ManagerRessource::getRessource("src/ressource/texture/dirt.jpg");
	texture[3] = ManagerRessource::getRessource("src/ressource/texture/bomberman.jpg");



	//test de model
	Ressource *object[2];
	object[0] =  ManagerRessource::getRessource("src/ressource/object/bomberman.obj");
	object[1] =  ManagerRessource::getRessource("src/ressource/object/bomb.obj");

	Object *objet1= new Object();
	objet1->attach(new Cube(1,texture[0]));
	objet1->setScale(2,2,2);
	objet1->setCoordonnes(0,-4,0);

	Object *objet2= new Object();
	objet2->attach(new Cube(2, texture[2]));
	objet2->setScale(2,2,2);
	objet2->setCoordonnes(0,6,0);

	Object *objet3 = new Object();
	objet3->attach(object[1], texture[1]);
	objet3->setScale(0.5,0.5,0.5);
	objet3->setCoordonnes(4,0,0);
	//objet3->rotate(0,-45,-90);

	Object *objet4 = new Object();
	objet4->attach(object[0], texture[3]);
	objet4->setScale(0.3,0.3,0.3);
	objet4->setCoordonnes(2,0,0);
	//objet4->rotate(0,-45,-90);


	engine.addSceneObject(objet1,scene1);
	engine.addSceneObject(objet2,scene1);
	engine.addSceneObject(objet3,scene1);
	engine.addSceneObject(objet4,scene1);


	
	
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
					//objet3->translation(-0.1,0,0);
						objet4->rotate(2,0,0);
					break;
					case SDLK_DOWN: 
					//objet3->translation(0.1,0,0);
					objet4->rotate(0,2,0);
					break;
					case SDLK_LEFT: 
					//scene1->translation(0,-0.1,0);
					objet3->rotate(0,0,2);
					break;
					case SDLK_RIGHT: 
					//scene1->translation(0,0.1,0);
					break;
				}
		}
		engine.draw(camera);
		
	}
	return 0;
}