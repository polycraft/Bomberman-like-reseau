#ifndef LOADERMAP_H
#define LOADERMAP_H

struct SHeader {
int width;//largeur
int height;//longueur
int gameType;
};



#include "Loader.h";
#include "../Exception/Exception.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;





namespace Engine
{

    class LoaderMap : public Loader
    {
        public:
           LoaderMap();
			virtual ~LoaderMap();

			/**
			Charge et retourne une map
			**/
			Ressource *load(string &name) throw(ExceptionNoFileFound);

			void free(Ressource &ressource) throw(ExceptionBadRessource);

		private:




    };
}
#endif // LOADERMAP_H