#ifndef SOUND_H
#define SOUND_H

#include "Ressource.h"
#include <fmodex/fmod.h>

namespace Engine
{
    class Sound : public Ressource
    {
        public:
            Sound();
            virtual ~Sound();

            FMOD_SOUND *getSound();

        protected:
        private:
    };
}
#endif // SOUND_H
