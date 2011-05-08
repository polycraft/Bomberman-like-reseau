#ifndef CUBE_H
#define CUBE_H
#include "Meshe.h"

namespace Engine
{
    class Cube : public Meshe
    {
        public:
            Cube(double height,Ressource *noTexture);
			Cube(double height,Texture *noTexture);
            ~Cube();
		private:
			void construireCube(double height);


    };
}
#endif // OBJECTDATA_H