#include "LoaderSample.h"
#include <string>
#include "../SoundEngine/SoundEngine.h"
#include "../Sound.h"

using namespace std;

namespace Engine
{
LoaderSample::LoaderSample()
{
    //ctor
}

LoaderSample::~LoaderSample()
{
    //dtor
}

Ressource * LoaderSample::load(string &name) throw(ExceptionNoFileFound)
{
    FMOD_SOUND *sample = NULL;
    if ((FMOD_System_CreateSound(SoundEngine::getInstance()->getSystem(), name.c_str(), FMOD_CREATESAMPLE, 0, &sample)) != FMOD_OK)
	{
		throw new ExceptionNoFileFound();
	}

	return new Sound(name,sample);
}
}
