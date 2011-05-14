#include "Sound.h"
#include "Ressource.h"
#include <string>
#include <fmodex/fmod.h>

namespace Engine
{
Sound::Sound(std::string &name,FMOD_SOUND *sound):Ressource(name)
{
    this->sound=sound;
}

Sound::~Sound()
{
    //dtor
}

FMOD_SOUND *Sound::getData()
{
    return sound;
}
}
