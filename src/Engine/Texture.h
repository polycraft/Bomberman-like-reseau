#ifndef TEXTURE_H
#define TEXTURE_H

#include "util/windows.h"
#ifdef WINDOWS
  #include <windows.h>
#endif
#include "Ressource.h"
#include <string>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

namespace Engine
{
    class Texture : public Ressource
    {
		public:
			Texture(string &name,GLuint texture);
			virtual ~Texture();

			GLuint getTexture();
		protected:
		private:
			GLuint texture;


	};
}

#endif // TEXTURE_H
