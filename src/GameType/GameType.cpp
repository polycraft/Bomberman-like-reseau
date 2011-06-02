#include "GameType.h"


#include "../Type/Bomb.h"
#include "../Game.h"
#include "../Type/ManagerExplosion.h"
#include "../Type/ExplosionFlare.h"



GameType::GameType(Game *game,int partTime, Engine::Socket *socket):partTime(partTime),game(game),socket(socket)
{
}

GameType::~GameType()
{

}

Game* GameType::getGame()
{
    return game;
}

Engine::Socket* GameType::getSocket()
{
	return this->socket;
}

void GameType::updateTimer(unsigned int delay)
{

}