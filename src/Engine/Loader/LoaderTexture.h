#ifndef LOADERTEXTURE_H
#define LOADERTEXTURE_H


#include "../util/windows.h"
#ifdef WINDOWS
  #include <windows.h>
#endif


#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Loader.h"
#include "../Ressource.h"
#include "../Exception/Exception.h"
#include "../Exception/ExceptionNoFileFound.h"
#include "../Exception/ExceptionBadRessource.h"

#include "../Texture.h"

#include <cstring>
#include <cstdlib>

using namespace std;

#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE 0x812F
#endif

namespace Engine
{
class LoaderTexture : public Loader
{
	public:
		LoaderTexture();
		virtual ~LoaderTexture();

		/**
        Charge et retourne une texture
        **/
		Ressource *load(string &name) throw(ExceptionNoFileFound);

		void free(Ressource &ressource) throw(ExceptionBadRessource);

	private:
		GLuint loadTexture(const char * filename,bool useMipMap = true);
		SDL_Surface * flipSurface(SDL_Surface * surface);


};
}


#endif // LOADERTEXTURE_H