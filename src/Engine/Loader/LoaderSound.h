#ifndef LOADERSOUND_H
#define LOADERSOUND_H

#include "../Ressource.h"
#include "Loader.h"

namespace Engine
{
class LoaderSound : public Loader
{
    public:
        void free(Ressource &ressource) throw(ExceptionBadRessource);
        virtual ~LoaderSound();
    protected:
        LoaderSound();//Classe abstraite
};
}
#endif // LOADERSOUND_H
