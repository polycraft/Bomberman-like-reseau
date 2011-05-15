#ifndef GAMETYPE_H
#define GAMETYPE_H
class Bomb;
#include "../Type/Bomb.h"
#include "../Game.h"

class GameType
{

public:
	GameType(Game *game,int partTime);
	virtual ~GameType();
	virtual void explode(Bomb* bomb,int speed,int power)=0;
    virtual void update()=0;
    Game* getGame();
protected:
    Game* game;
private:
	int partTime;

};



#endif // GAMETYPE_H
