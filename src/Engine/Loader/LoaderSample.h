#ifndef LOADERSAMPLE_H
#define LOADERSAMPLE_H

#include <string>
#include "Loader.h"
#include "LoaderSound.h"
#include "../Ressource.h"
#include "../Exception/ExceptionNoFileFound.h"

using namespace std;

namespace Engine
{
class LoaderSample : public LoaderSound
{
    public:
        LoaderSample();
        virtual ~LoaderSample();
        /**
        Charge et retourne un son
        **/
        Ressource *load(string &name) throw(ExceptionNoFileFound);
};
}
#endif // LOADERSAMPLE_H
