#ifndef EFFECT_H
#define EFFECT_H

class Effect;

#include "../../Engine/util/IObserverTimer.h"
#include "../../Engine/util/Timer.h"
#include "../Bomberman.h"






        class Effect : public Engine::IObserverTimer
        {
        public:
            Effect();
            virtual ~Effect();
			virtual void enableEffect(Bomberman *bomberman);
			void updateTimer(unsigned int delay);

        protected:
			Bomberman *bomberman;
        };


#endif // EFFECT_H