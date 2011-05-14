#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <fmodex/fmod.h>
#include <stdlib.h>

#include "../Sound.h"

namespace Engine
{
/**
Moteur de gestion de son à base de FMOD fx
**/
class SoundEngine
{
    public:

        virtual ~SoundEngine();

        /**
        Retourne l'instance du singleton
        **/
        static SoundEngine *getInstance();

        /**
        Retourne systeme
        **/
        FMOD_SYSTEM *getSystem();

        /**
        Joue un son
        **/
        void playSound(Ressource &sound) throw(ExceptionBadRessource);

        /**
        Joue un son sur un chanel
        **/
        void playSound(FMOD_CHANNELINDEX channel,Ressource &sound) throw(ExceptionBadRessource);

        /**
        Joue un son
        **/
        void playSound(Sound &sound);

        /**
        Joue un son sur un chanel
        **/
        void playSound(FMOD_CHANNELINDEX channel,Sound &sound);

        /**
        Met en pause ou reprend la lecture d'un canal
        **/
        void togglePauseChannel(unsigned int channel);

        /**
        Régle le volume d'un canal
        **/
        void setVolumeChannel(unsigned int channel,float volume);

        /**
        Arrete la lecture sur un canal
        **/
        void stopChannel(unsigned int channel);

         /**
        Met en pause ou reprend la lecture de tous les canaux
        **/
        void togglePauseAllChannel();

        /**
        Régle le volume de tous les canaux
        **/
        void setVolumeAllChannel(float volume);

        /**
        Arrete la lecture de tous les canaux
        **/
        void stopAllChannel();

    protected:
    private:
        static SoundEngine *instance;
        FMOD_SYSTEM *system;

        SoundEngine(unsigned int nbChannel=32);

        /**
        Retourne un canal à partir de son id
        **/
        FMOD_CHANNEL *getChannel(unsigned int idChannel);

        /**
        Retourne le canal maitre
        **/
        FMOD_CHANNELGROUP *getChannelGroup();
};

}
#endif // SOUNDENGINE_H
