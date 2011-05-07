#ifndef MESHE_H
#define MESHE_H

#include "../util/windows.h"
#ifdef WINDOWS
  #include <windows.h>
#endif
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>

namespace Engine
{
    class Meshe
    {
		friend class Object;
        public:
            Meshe();
            virtual ~Meshe();

        protected:
            GLfloat* point;
			int nbPoint;
            GLuint* indice;
			int nbIndice;
            double* texture;
			int nbTexture;


    };
}
#endif // OBJECTDATA_H