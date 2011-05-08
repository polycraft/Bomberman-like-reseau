#ifndef LOADERMUSIC_H
#define LOADERMUSIC_H

#include <string>
#include "Loader.h"
#include "LoaderSound.h"
#include "../Ressource.h"
#include "../Exception/ExceptionNoFileFound.h"

using namespace std;

namespace Engine
{
class LoaderMusic : public LoaderSound
{
    public:
        LoaderMusic();
        virtual ~LoaderMusic();
        /**
        Charge et retourne un son
        **/
        Ressource *load(string &name) throw(ExceptionNoFileFound);
};
}
#endif // LOADERMUSIC_H

