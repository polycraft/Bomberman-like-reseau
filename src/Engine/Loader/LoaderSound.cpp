#include "LoaderSound.h"
#include "../Sound.h"
#include "../Ressource.h"
#include <exception>
#include "../Exception/ExceptionBadRessource.h"

namespace Engine
{
LoaderSound::LoaderSound()
{
    //ctor
}

LoaderSound::~LoaderSound()
{
    //dtor
}

void LoaderSound::free(Ressource &ressource) throw (ExceptionBadRessource)
{
    Sound *sound=Ressource::getRessource<Sound>(ressource);
    FMOD_Sound_Release(sound->getData());
}
}
