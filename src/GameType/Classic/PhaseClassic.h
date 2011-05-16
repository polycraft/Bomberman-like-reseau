#ifndef PHASECLASSIC_H
#define PHASECLASSIC_H

#include "../Phase.h"
#include "../../Engine/NetworkEngine/IObserverSocketRecv.h"
#include "Classic.h"

namespace GameTypeSpace
{
    namespace ClassicSpace
    {
        class PhaseClassic : public Phase,Engine::IObserverSocketRecv
        {
        public:
            PhaseClassic(GameTypeSpace::Classic *gameType,CollisionDetector *collision);
            virtual ~PhaseClassic();
            virtual void updateRecv(Socket *,const char*,int size)=0;
        protected:
            Classic *gameType;
        };
    }
}

#endif // PHASE_H
