#ifndef ENGINE_H
#define ENGINE_H

#include "GraphicEngine/GraphicEngine.h"
#include "EventEngine/EventEngine.h"

namespace Engine
{
	class MainEngine
	{
	public:
		MainEngine();
		~MainEngine();
		GraphicEngine* getGengine();
        EventEngine* getEventEngine();
        bool run(Camera *camera);
	private:
		GraphicEngine *Gengine;
        EventEngine *eventEngine;

	};
}


#endif // ENGINE_H
