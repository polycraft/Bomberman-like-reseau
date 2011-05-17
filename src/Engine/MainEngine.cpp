#include "MainEngine.h"
#include "util/Timer.h"
namespace Engine
{
	MainEngine::MainEngine()
	{
		this->Gengine = new GraphicEngine("TestBomber",800, 600,1,1);
		this->eventEngine=new EventEngine();
	}
	MainEngine::~MainEngine()
	{
	}

	GraphicEngine* MainEngine::getGengine()
	{
		return this->Gengine;
	}

    EventEngine* MainEngine::getEventEngine()
	{
		return this->eventEngine;
	}

	bool MainEngine::run(Camera *camera)
	{
        bool tmp=this->eventEngine->update();
        this->Gengine->draw(camera);
        Timer::getTimer()->update();
        return tmp;
	}
}
