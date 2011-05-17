#include "GameType.h"

GameType::GameType(Game *game,int partTime):partTime(partTime),game(game)
{

}

GameType::~GameType()
{

}

Game* GameType::getGame()
{
    return game;
}


