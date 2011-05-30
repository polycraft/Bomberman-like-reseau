#ifndef LOADERMAP_H
#define LOADERMAP_H

#include "../Engine/Loader/Loader.h"
#include "../Engine/Exception/Exception.h"
#include "../Engine/Ressource.h"
#include "../Map.h"

struct SHeader {
int width;//largeur
int height;//longueur
EGameType gameType;
};



class LoaderMap : public Engine::Loader
{
    public:
       LoaderMap();
        virtual ~LoaderMap();

        /**
        Charge et retourne une map
        **/
        Engine::Ressource *load(std::string &name) throw(Engine::ExceptionNoFileFound);

        void free(Engine::Ressource &ressource) throw(Engine::ExceptionBadRessource);
};

#endif // LOADERMAP_H
