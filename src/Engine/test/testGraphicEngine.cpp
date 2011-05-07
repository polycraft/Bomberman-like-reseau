#include "testGraphicEngine.h"
using namespace Engine;
int testGraphicEngine()
{
	GraphicEngine engine("TestGraphicEngine",400, 400,1,1);
	Camera *camera = new Camera(6, 0, 6, 0, 0, 0, 0, 0, 1);
	engine.addCamera(camera);

	Scene *scene1 = new Scene(Engine::TS_Static);
	engine.addScene(scene1);

	Object *objet1= new Object();
	objet1->attach(new Cube(1));

	Object *objet2= new Object();
	objet2->attach(new Cube(2));

	
	engine.addSceneObject(objet1,scene1);
	engine.addSceneObject(objet2,scene1);

	

	objet1->translation(0,2,0);
	objet2->translation(0,-2,0);
	
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
					objet1->translation(-0.1,0,0);
					break;
					case SDLK_DOWN: 
					objet1->translation(0.1,0,0);
					break;
					case SDLK_LEFT: 
					scene1->translation(0,-0.1,0);
					break;
					case SDLK_RIGHT: 
					scene1->translation(0,0.1,0);
					break;
				}
		}
		engine.draw(camera);
		
	}
	return 0;
}