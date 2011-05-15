#include "Phase.h"


Phase::Phase(GameType *gameType,CollisionDetector *collision):gameType(gameType)
{
    setCollisionDetector(collision);
}




void Phase::end( int next)
{
    this->next=next;
}

int Phase::update()
{
    switch(etat)
    {
        case E_Init:
            this->init();
        break;
        case E_Run:
            this->run();
        break;
    }
    return next;
}

void Phase::nextEtat()
{
    int tmp=this->etat;

    this->etat=static_cast<EEtat>(tmp+1);
}


void Phase::setCollisionDetector(CollisionDetector *collision)
{
    this->collision=collision;
}
