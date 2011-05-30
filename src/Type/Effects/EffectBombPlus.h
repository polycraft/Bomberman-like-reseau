#ifndef EFFECTBOMBPLUS_H
#define EFFECTBOMBPLUS_H

#include "Effect.h"

class Bomberman;


class EffectBombPlus : public Effect
{
public:
    EffectBombPlus();
    virtual ~EffectBombPlus();
    void enableEffect(Bomberman *bomberman);

};



#endif // EFFECTBOMBPLUS_H
