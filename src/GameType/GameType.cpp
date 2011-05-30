#include "GameType.h"

GameType::GameType(Game *game,int partTime,Socket *socket):partTime(partTime),game(game)
{
	this->socket = socket;
}

GameType::~GameType()
{

}

Game* GameType::getGame()
{
    return game;
}


