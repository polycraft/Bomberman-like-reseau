#ifndef ENGINE_H
#define ENGINE_H

#include "GraphicEngine/GraphicEngine.h"

namespace Engine
{
	class MainEngine
	{
	public:
		MainEngine();
		~MainEngine();
		GraphicEngine* getGengine();

	private:
		GraphicEngine *Gengine;


	};
}


#endif // ENGINE_H
