#ifndef GAMETYPE_H
#define GAMETYPE_H


class Bomb;
class Game;
class ExplosionFlare;
class ManagerExplosion;
#include "../Engine/NetworkEngine/Socket.h"

class GameType
{

public:
	GameType(Game *game,int partTime, Engine::Socket *socket);
	virtual ~GameType();
	virtual void update()=0;
    virtual void explode(Bomb* bomb,int speed,int power)=0;
    virtual void updateExplosion(ExplosionFlare *flare,int power,int x,int y)=0;
    virtual void destroyManagerExplosion(ManagerExplosion* manager)=0;
    Game* getGame();
protected:
    Game* game;
private:
	Engine::Socket *socket;
	int partTime;

};



#endif // GAMETYPE_H
