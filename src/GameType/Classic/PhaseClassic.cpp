#include "PhaseClassic.h"

namespace GameTypeSpace
{
	namespace ClassicSpace
	{
        PhaseClassic::PhaseClassic(GameTypeSpace::Classic *gameType,CollisionDetector *collision)  : gameType(gameType),Phase(collision)
        {
            //ctor
        }

        PhaseClassic::~PhaseClassic()
        {
            //dtor
        }
	}
}
