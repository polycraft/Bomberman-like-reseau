#include "Phase.h"


Phase::Phase(CollisionDetector *collision)
{
    setCollisionDetector(collision);
    this->etat=E_Init;
    this->next=0;
}




void Phase::end( int next)
{
    this->next=next;
}

int Phase::update()
{
    switch(this->etat)
    {
        case E_Init:
            this->init();
        break;
        case E_Run:
            this->run();
        break;
        default:
            this->end(1);
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
