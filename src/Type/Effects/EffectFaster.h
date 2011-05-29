#ifndef EFFECTFASTER_H
#define EFFECTFASTER_H

#include "Effect.h"

class Bomberman;


class EffectFaster : public Effect
{
public:
    EffectFaster();
    virtual ~EffectFaster();
    void enableEffect(Bomberman *bomberman);

};



#endif // EFFECTFASTER_H
