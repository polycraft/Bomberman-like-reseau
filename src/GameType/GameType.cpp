#include "GameType.h"

GameType::GameType(Game *game,int partTime):partTime(partTime),game(game)
{

}

GameType::~GameType()
{

}

void GameType::explode(Bomb* bomb,int speed,int power)
{

}

Game* GameType::getGame()
{
    return game;
}


