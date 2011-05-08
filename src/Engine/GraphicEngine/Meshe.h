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
#include "../Ressource.h"
#include "../Texture.h"

namespace Engine
{
    class Meshe
    {
		friend class Object; //pour eviter des getter setter
        public:
            Meshe(Texture* texture);
			Meshe(Ressource* texture);
            virtual ~Meshe();

        protected:
            GLfloat* point;
			int nbPoint;
            GLuint* indice;
			int nbIndice;
            GLfloat* texture;
			int nbTexture;
			GLuint noTexture;


    };
}
#endif // OBJECTDATA_H