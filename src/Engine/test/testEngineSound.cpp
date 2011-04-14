#include "testEngineSound.h"
#include "../SoundEngine/SoundEngine.h"
#include "../ManagerRessource.h"
#include "../Ressource.h"

using namespace Engine;

int testEngineSound()
{

    SoundEngine *s = SoundEngine::getInstance();

    //Chargement des sons
    Ressource *sound[2];
    sound[0]=ManagerRessource::getRessource("ressource/sound/DYNAMITE.mp3");
    sound[1]=ManagerRessource::getRessource("ressource/sound/Beigne5.wav");

    s->playSound(*(sound[0]));
    s->playSound(*(sound[1]));

    for(int i=0;i<20;i++)
    {
        if(i%2)
            s->playSound(*(sound[0]));
        else
            s->playSound(*(sound[1]));
        sleep(1);
    }
}
