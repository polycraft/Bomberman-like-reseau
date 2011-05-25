#ifndef EFFECTFASTER
#define EFFECTFASTER



#include "Effect.h"


        class EffectFaster : public Effect
        {
        public:
            EffectFaster();
            virtual ~EffectFaster();
			void enableEffect(Bomberman *bomberman);

        };


#endif // EFFECTFASTER