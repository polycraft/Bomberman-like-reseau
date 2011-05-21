#include "MainEngine.h"
#include "util/Timer.h"
namespace Engine
{
	MainEngine::MainEngine(int engine)
	{
	    this->Gengine=NULL;
	    this->eventEngine=NULL;

	    if(engine & Engine_Graphic)
            this->Gengine = new GraphicEngine("TestBomber",800, 600,1,1);
        if(engine & Engine_Event)
            this->eventEngine=new EventEngine();
	}
	MainEngine::~MainEngine()
	{
	}

	GraphicEngine* MainEngine::getGengine()
	{
	    if(Gengine==NULL)
            throw ExceptionNoEngine();
		return this->Gengine;
	}

    EventEngine* MainEngine::getEventEngine()
	{
	    if(eventEngine==NULL)
            throw ExceptionNoEngine();
		return this->eventEngine;
	}

	bool MainEngine::run(Camera *camera)
	{
        bool tmp=getEventEngine()->update();
        getGengine()->draw(camera);
        Timer::getTimer()->update();
        return tmp;
	}
}
