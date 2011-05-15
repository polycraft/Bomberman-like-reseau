#ifndef FIRE_H
#define FIRE_H
#include "Meshe.h"

namespace Engine
{
    class Fire : public Meshe
    {
        public:
            Fire();
            ~Fire();
		private:
			void buildFire();



    };
}
#endif // FIRE_H