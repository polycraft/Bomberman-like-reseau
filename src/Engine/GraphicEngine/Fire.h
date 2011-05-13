#ifndef FIRE_H
#define FIRE_H
#include "Meshe.h"

namespace Engine
{
    class Fire : public Meshe
    {
        public:
            Fire(Ressource *noTexture);
			Fire(Texture *noTexture);
            ~Fire();
		private:
			void buildFire();



    };
}
#endif // FIRE_H