#ifndef EFFECTFASTER_H
#define EFFECTFASTER_H

class Effect;

#include "Effect.h"


        class EffectFaster : public Effect
        {
        public:
            EffectFaster();
            virtual ~EffectFaster();
			void enableEffect(Bomberman *bomberman);

        };



#endif // EFFECTFASTER_H