#ifndef LOADERTOBJET_H
#define LOADERTOBJET_H


#include "../util/windows.h"
#ifdef WINDOWS
  #include <windows.h>
#endif

#include <map>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Loader.h"
#include "../Ressource.h"
#include "../Exception/Exception.h"
#include <vector>
#include "../Model.h"

using namespace std;

enum Etats
{
	SEtatDebut,
	SEtat1,
	SEtat2,
	SEtat3,
	SEtat4
};

namespace Engine
{
class LoaderObject : public Loader
{
	public:
		LoaderObject();
		virtual ~LoaderObject();

		/**
        Charge et retourne une texture
        **/
		Ressource *load(string &name) throw(ExceptionNoFileFound);

		void free(Ressource &ressource) throw(ExceptionBadRessource);

	private:
		vector<double> point;
		vector<int> indice;
		vector<double> texture;
		//fonction de parsage
		void parserObject(string file);

};
}


#endif // LOADERTOBJET_H