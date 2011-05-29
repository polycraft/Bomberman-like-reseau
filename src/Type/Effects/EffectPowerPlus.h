#ifndef EFFECTPOWERPLUS_H
#define EFFECTPOWERPLUS_H

#include "Effect.h"

class Bomberman;


class EffectPowerPlus : public Effect
{
public:
    EffectPowerPlus();
    virtual ~EffectPowerPlus();
    void enableEffect(Bomberman *bomberman);

};



#endif // EFFECTPOWERPLUS_H
