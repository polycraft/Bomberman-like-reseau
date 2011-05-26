#ifndef EFFECTFASTER_H
#define EFFECTFASTER_H

class EffectFaster;

#include "Effect.h"
#include "../Bomberman.h"

        class EffectFaster : public Effect
        {
        public:
            EffectFaster();
            virtual ~EffectFaster();
			void enableEffect(Bomberman *bomberman);

        };



#endif // EFFECTFASTER_H