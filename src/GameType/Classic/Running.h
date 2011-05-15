#ifndef RUNNING_H
#define RUNNING_H

#include "../Phase.h"

namespace GameTypeSpace
{
	namespace Classic
	{
		class Running : public Phase
		{

		public:
			Running(CollisionDetector *collision);
			virtual ~Running();
			void init();
			virtual void run();
			virtual void updateTimer();

		private:

		};
	}
}



#endif // RUNNING_H
