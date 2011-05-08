#ifndef LOADER_H
#define LOADER_H

#include <string>
#include "../Ressource.h"

using namespace std;

namespace Engine
{
/**
Interface d'un loader
**/
class Loader
{
    public:
        /**
        Charge une ressource
        **/
        virtual Ressource *load(string &name)=0;

        /**
        Libere une ressource
        **/
        virtual void free(Ressource &ressource) throw(ExceptionBadRessource) =0 ;

        virtual ~Loader(){};
    protected:
        Loader(){};//Classe abstraite
};
}

#endif // LOADER_H
