#ifndef SOUND_H
#define SOUND_H

#include "Ressource.h"
#include "Loader/LoaderSound.h"
#include <fmodex/fmod.h>
#include <string>

namespace Engine
{
    class Sound : public Ressource
    {
        public:
            Sound(string &name,FMOD_SOUND *sound);
            virtual ~Sound();

            FMOD_SOUND *getData();

        protected:
        private:
            FMOD_SOUND *sound;
    };
}
#endif // SOUND_H
