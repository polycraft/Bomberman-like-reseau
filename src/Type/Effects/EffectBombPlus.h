#ifndef EFFECTBOMBPLUS_H
#define EFFECTBOMBPLUS_H

class Effect;

#include "Effect.h"


        class EffectBombPlus : public Effect
        {
        public:
            EffectBombPlus();
            virtual ~EffectBombPlus();
			void enableEffect(Bomberman *bomberman);

        };



#endif // EFFECTBOMBPLUS_H