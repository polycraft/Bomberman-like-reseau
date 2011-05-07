#include "testGraphicEngine.h"
using namespace Engine;
int testGraphicEngine()
{
	GraphicEngine engine("TestGraphicEngine",400, 400,1,1);
	Camera *camera = new Camera();
	engine.addCamera(camera);

	Scene *scene = new Scene(Engine::TS_Static);
	engine.addScene(scene);

	Object *objet1= new Object();
	Cube *cube = new Cube(1);
	objet1->attach(cube);
	
	engine.addSceneObject(objet1,scene);


	engine.draw(camera);

	
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
		}
	}
	return 0;
}