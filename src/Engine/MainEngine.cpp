#include "MainEngine.h"

namespace Engine
{
	MainEngine::MainEngine()
	{
		this->Gengine = new GraphicEngine("TestBomber",800, 600,1,1);
	}
	MainEngine::~MainEngine()
	{
	}

	GraphicEngine* MainEngine::getGengine()
	{
		return this->Gengine;
	}
}