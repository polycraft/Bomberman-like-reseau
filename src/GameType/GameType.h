#ifndef GAMETYPE_H
#define GAMETYPE_H
class Bomb;
#include "../Type/Bomb.h"
#include "../Game.h"
#include "../Type/ManagerExplosion.h"
#include "../Type/ExplosionFlare.h"

class GameType
{

public:
	GameType(Game *game,int partTime);
	virtual ~GameType();
	virtual void update()=0;
    virtual void explode(Bomb* bomb,int speed,int power)=0;
    virtual void updateExplosion(ExplosionFlare *flare,int power,int x,int y)=0;
    virtual void destroyManagerExplosion(ManagerExplosion* manager)=0;
    Game* getGame();
protected:
    Game* game;
private:
	int partTime;

};



#endif // GAMETYPE_H
