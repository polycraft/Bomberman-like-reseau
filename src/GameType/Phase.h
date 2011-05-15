#ifndef PHASE_H
#define PHASE_H

#include "../CollisionDetector.h"
#include "../Engine/EventEngine/IEventListener.h"
#include "GameType.h"

using namespace Engine;

typedef enum EEtat
{
    E_Init,
    E_Run
} EEtat;

class Phase : public IEventListener
{

public:
	Phase(GameType *gameType,CollisionDetector *collision);
	virtual ~Phase(){};
	virtual void init()=0;
	virtual void run()=0;
	void end( int next=1);
	void nextEtat();
	virtual void executeAction(const Engine::stateEvent &event)=0;
	void setCollisionDetector(CollisionDetector *collision);

    int update();
protected:
    GameType *gameType;
private:
	CollisionDetector *collision;
	EEtat etat;
	int next;
};



#endif // PHASE_H
