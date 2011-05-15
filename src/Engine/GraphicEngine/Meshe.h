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
			Meshe();//pour les Model dont la texture est appliqué apres
            Meshe(Texture* texture);
			Meshe(Ressource* texture);
			virtual ~Meshe();
			//pour changer les textures
			void setTexture(Texture* texture);
			void setTexture(Ressource* texture);

			void moveTexture();


        protected:
            GLfloat* point;
			int nbPoint;
            GLuint* indice;
			int nbIndice;
            GLfloat* texture;
			int nbTexture;

			//seulement pour les textures animées:
			double *textureAnim;
			int tailleTextureAnim;
			int cycleTexture;

			bool hasTransparentTexture;




    };
}
#endif // OBJECTDATA_H