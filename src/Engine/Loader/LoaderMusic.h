#ifndef LOADERMUSIC_H
#define LOADERMUSIC_H

#include <string>
#include "Loader.h"
#include "../Ressource.h"
#include "../Exception/ExceptionNoFileFound.h"

using namespace std;

namespace Engine
{
class LoaderMusic : public Loader
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

