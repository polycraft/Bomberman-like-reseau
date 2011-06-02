#ifndef GAMETYPE_H
#define GAMETYPE_H


class Bomb;
class Game;
class ExplosionFlare;
class ManagerExplosion;

#include "../Engine/NetworkEngine/Socket.h"
#include "../Engine/util/IObserverTimer.h"
#include "../Engine/util/Timer.h"

class GameType : public Engine::IObserverTimer
{

public:
	GameType(Game *game,int partTime, Engine::Socket *socket);
	virtual ~GameType();
	virtual void update()=0;
    virtual void explode(Bomb* bomb,int speed,int power)=0;
    virtual void updateExplosion(ExplosionFlare *flare,int power,int x,int y)=0;
    virtual void destroyManagerExplosion(ManagerExplosion* manager)=0;
	virtual void updateTimer(unsigned int delay);
	Engine::Socket* getSocket();
    Game* getGame();
protected:
    Game* game;
private:
	Engine::Socket *socket;
	int partTime;

};



#endif // GAMETYPE_H
