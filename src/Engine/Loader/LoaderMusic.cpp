#include "LoaderMusic.h"
#include <string>
#include "../SoundEngine/SoundEngine.h"
#include "../Sound.h"

using namespace std;

namespace Engine
{
LoaderMusic::LoaderMusic()
{
    //ctor
}

LoaderMusic::~LoaderMusic()
{
    //dtor
}

Ressource * LoaderMusic::load(string &name) throw(ExceptionNoFileFound)
{
    FMOD_SOUND *music = NULL;
    if ((FMOD_System_CreateSound(SoundEngine::getInstance()->getSystem(), name.c_str(), FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &music)) != FMOD_OK)
	{
		throw new ExceptionNoFileFound();
	}

	return new Sound(name,music);
}

}

