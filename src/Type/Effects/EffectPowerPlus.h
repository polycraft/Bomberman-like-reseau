#ifndef EFFECTPOWERPLUS_H
#define EFFECTPOWERPLUS_H

class Effect;

#include "Effect.h"


        class EffectPowerPlus : public Effect
        {
        public:
            EffectPowerPlus();
            virtual ~EffectPowerPlus();
			void enableEffect(Bomberman *bomberman);

        };



#endif // EFFECTPOWERPLUS_H