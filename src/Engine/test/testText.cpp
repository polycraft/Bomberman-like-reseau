#include "testText.h"
using namespace Engine;
int testText()
{
    GraphicEngine engine("TestGraphicEngine",800, 600,1,1);
	Camera *camera = new Camera(6, 0, 6, 0, 0, 0, 0, 0, 1);
	engine.addCamera(camera);

	ManagerFont* font=new ManagerFont("src/ressource/font/font.ttf",24);
	string s("Blablbla");
	Text text(s,50.0,100.0);
	text.setColor(1,1,1,1);
	font->addText(&text);

	engine.getManagerText().addFont(font);

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
		engine.draw(camera);

	}
}
