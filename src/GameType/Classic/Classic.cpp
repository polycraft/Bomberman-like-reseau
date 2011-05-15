#include "Classic.h"

#include "Initialisation.h"
#include "Running.h"
#include "HurryUp.h"

namespace GameTypeSpace
{
    using namespace ClassicSpace;

	Classic::Classic(Game *game):GameType(game,10)
	{
	    phaseCurrent=P_Initialisation;

	    collision=new CollisionDetector(game->getMap());

	    phase[P_Initialisation]=new Initialisation(this,collision);
	    phase[P_Running]=new Running(this,collision);
	    phase[P_HurryUp]=new HurryUp(this,collision);
	}

	Classic::~Classic()
	{
	    delete collision;
	    delete phase[P_Initialisation];
	    delete phase[P_Running];
	    delete phase[P_HurryUp];
	}


	void Classic::update()
	{
        EPhase nextPhase=static_cast<EPhase>(getPhase(phaseCurrent)->update());
        int tmp;
        switch(nextPhase)
        {
            case P_Current:

            break;
            case P_Next:
                tmp=phaseCurrent+1;
                phaseCurrent=static_cast<EPhase>(tmp);
            break;
            default:
                phaseCurrent=nextPhase;
            break;
        }
	}

	void Classic::explode(Bomb* bomb,int speed,int power)
	{
	}

	Bomberman* Classic::getPlayer()
	{
	    return player;
	}

    vector<Bomberman*>& Classic::getPlayerNetwork()
    {
        return playerNetwork;
    }

    Phase* Classic::getPhase(EPhase phase)
    {
        switch(phase)
        {
            case P_Current:
                return this->phase[phaseCurrent];
            break;
            case P_Next:
                return this->phase[phaseCurrent+1];
            break;
            default:
                return this->phase[phase-2];
            break;
        }
    }
}
