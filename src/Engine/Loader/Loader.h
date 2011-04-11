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

        virtual ~Loader(){};
    private:
        Loader(){};//Classe abstraite
};
}

#endif // LOADER_H
