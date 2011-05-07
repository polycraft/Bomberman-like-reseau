#include "testGraphicEngine.h"
using namespace Engine;
int testGraphicEngine()
{
	GraphicEngine engine("TestGraphicEngine",400, 400,1,1);
	Camera *camera = new Camera(2, 0, 2, 0, 0, 0, 0, 0, 1);
	engine.addCamera(camera);

	Scene *scene = new Scene(Engine::TS_Static);
	engine.addScene(scene);

	Object *objet1= new Object();
	Cube *cube = new Cube(1);
	objet1->attach(cube);

	
	engine.addSceneObject(objet1,scene);

	



	
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
				}
		}
		engine.draw(camera);
		
	}
	return 0;
}