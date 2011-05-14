#ifndef LOADERMAP_H
#define LOADERMAP_H


#include "../GameType/GameType.h"
#include "../Map.h"
#include "../Type/Type.h"
#include "../Type/BreakableBloc.h"
#include "../Type/StaticBloc.h"
#include "../Type/Type.h"
#include "../Engine/Loader/Loader.h"
#include "../Engine/Exception/Exception.h"
#include "../Map.h"
#include <iostream>
#include <fstream>
#include <cstring>

struct SHeader {
int width;//largeur
int height;//longueur
EGameType gameType;
};




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
