#include "SoundEngine.h"
#include <fmodex/fmod.h>
#include "../Sound.h"
#include "../Ressource.h"

namespace Engine
{
//Initialisation de l'instance
SoundEngine *SoundEngine::instance = NULL;

SoundEngine::SoundEngine(unsigned int nbChannel)
{
    //Initialise fmod
    FMOD_System_Create(&system);
	FMOD_System_Init(system, nbChannel, FMOD_INIT_NORMAL, NULL);
}

SoundEngine::~SoundEngine()
{
    //libere fmod
    FMOD_System_Close(system);
	FMOD_System_Release(system);
}

SoundEngine *SoundEngine::getInstance()
{
    if(instance==NULL)
    {
        instance=new SoundEngine(32);
    }
    return instance;
}

FMOD_SYSTEM *SoundEngine::getSystem()
{
    return system;
}

void SoundEngine::playSound(Ressource &sound) throw(ExceptionBadRessource)
{
    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, Ressource::getRessource<Sound>(sound)->getData(), 0, NULL);
}

void SoundEngine::playSound(FMOD_CHANNELINDEX channel,Ressource &sound)throw(ExceptionBadRessource)
{
    FMOD_System_PlaySound(system, channel, Ressource::getRessource<Sound>(sound)->getData(), 0, NULL);
}

void SoundEngine::playSound(Sound &sound)
{
    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, sound.getData(), 0, NULL);
}

void SoundEngine::playSound(FMOD_CHANNELINDEX channel,Sound &sound)
{
    FMOD_System_PlaySound(system, channel, sound.getData(), 0, NULL);
}

FMOD_CHANNEL *SoundEngine::getChannel(unsigned int idChannel)
{
    FMOD_CHANNEL *channel;
    FMOD_System_GetChannel(system, idChannel, &channel);
    return channel;
}

void SoundEngine::togglePauseChannel(unsigned int channel)
{
    FMOD_BOOL etat;
    FMOD_CHANNEL *canal=getChannel(channel);
    FMOD_Channel_GetPaused(canal, &etat);

    if (etat == 1) // Si la chanson est en pause
        FMOD_Channel_SetPaused(canal, 0); // On enlève la pause
    else // Sinon, elle est en cours de lecture
        FMOD_Channel_SetPaused(canal, 1); // On met en pause
}

void SoundEngine::setVolumeChannel(unsigned int channel,float volume)
{
    FMOD_Channel_SetVolume(getChannel(channel),volume);
}

void SoundEngine::stopChannel(unsigned int channel)
{
    FMOD_Channel_Stop(getChannel(channel));
}

FMOD_CHANNELGROUP *SoundEngine::getChannelGroup()
{
    FMOD_CHANNELGROUP *channel;
    FMOD_System_GetMasterChannelGroup(system, &channel);
    return channel;
}

void SoundEngine::togglePauseAllChannel()
{
    FMOD_BOOL etat;
    FMOD_CHANNELGROUP *channel=getChannelGroup();
    FMOD_ChannelGroup_GetPaused(channel, &etat);

    if (etat == 1) // Si la chanson est en pause
        FMOD_ChannelGroup_SetPaused(channel, 0); // On enlève la pause
    else // Sinon, elle est en cours de lecture
        FMOD_ChannelGroup_SetPaused(channel, 1); // On met en pause
}

void SoundEngine::setVolumeAllChannel(float volume)
{
    FMOD_ChannelGroup_SetVolume(getChannelGroup(),volume);
}

void SoundEngine::stopAllChannel()
{
    FMOD_ChannelGroup_Stop(getChannelGroup());
}

}
