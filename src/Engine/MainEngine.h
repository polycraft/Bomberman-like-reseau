#ifndef ENGINE_H
#define ENGINE_H

#include "GraphicEngine/GraphicEngine.h"
#include "EventEngine/EventEngine.h"
#include "Exception/Exception.h"

namespace Engine
{
    typedef enum EEngine
    {
        Engine_Graphic=1,
        Engine_Event=2
    } EEngine;

	class MainEngine
	{
	public:
		MainEngine(int engine=3);
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
