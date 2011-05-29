#include "GameType.h"

#include "../Type/Bomb.h"
#include "../Game.h"
#include "../Type/ManagerExplosion.h"
#include "../Type/ExplosionFlare.h"

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


