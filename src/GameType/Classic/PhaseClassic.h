#ifndef PHASECLASSIC_H
#define PHASECLASSIC_H

#include "../Phase.h"
#include "../../Engine/NetworkEngine/IObserverSocketRecv.h"

namespace GameTypeSpace
{
    class Classic;
}
class CollisionDetector;
class GameType;

namespace GameTypeSpace
{
    namespace ClassicSpace
    {
        class PhaseClassic : public Phase,Engine::IObserverSocketRecv
        {
        public:
            PhaseClassic(GameTypeSpace::Classic *gameType,CollisionDetector *collision);
            virtual ~PhaseClassic();
            virtual void updateRecv(Engine::Socket *,Engine::Paquet& paquet)=0;
        protected:
            Classic *gameType;
        };
    }
}

#endif // PHASE_H
