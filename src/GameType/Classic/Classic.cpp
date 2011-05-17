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

	    phase[P_Initialisation-2]=new Initialisation(this,collision);
	    phase[P_Running-2]=new Running(this,collision);
	    phase[P_HurryUp-2]=new HurryUp(this,collision);

	    this->game->getEngine()->getEventEngine()->addListener(this);
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
	    Phase* t=getPhase(phaseCurrent);
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

	    int tmpX=bomb->getTransX();tmpX=tmpX/10-1;
	    int tmpY=bomb->getTransY();tmpY=tmpY/10-1;

	    this->game->getMap()->set(NULL,tmpX,tmpY);

	    new ManagerExplosion(tmpX,tmpY,bomb->getIdOwner(), speed, power, T_Emitter, this);

	    if(collision->detect(T_Explosion,tmpX-1,tmpY)==C_Nothing)
	    {
	        new ManagerExplosion(tmpX-1,tmpY,bomb->getIdOwner(), speed, power, T_Left, this);
	    }
        if(collision->detect(T_Explosion,tmpX+1,tmpY)==C_Nothing)
	    {
	        new ManagerExplosion(tmpX+1,tmpY,bomb->getIdOwner(), speed, power, T_Right, this);
	    }
        if(collision->detect(T_Explosion,tmpX,tmpY-1)==C_Nothing)
	    {
	        new ManagerExplosion(tmpX,tmpY-1,bomb->getIdOwner(), speed, power, T_Down, this);
	    }
        if(collision->detect(T_Explosion,tmpX,tmpY+1)==C_Nothing)
	    {
	        new ManagerExplosion(tmpX,tmpY+1,bomb->getIdOwner(), speed, power, T_Up, this);
	    }
	}

	void Classic::updateExplosion(ManagerExplosion *manager,int power,int x,int y)
	{
        switch(manager->getType())
        {
            case T_Left:
                x-=power;
                break;
            case T_Right:
                x+=power;
                break;
            case T_Up:
                y+=power;
            break;
            case T_Down:
                y-=power;
            break;
        }
        Type *object;
        switch(this->collision->detect(T_Explosion,x,y))
        {
            case C_Explose:
                object=this->game->getMap()->get(x,y);
                if(object->getType()==T_Bomb)
                {
                    dynamic_cast<Bomb*>(this->game->getMap()->get(x,y))->explode();
                }
                else if(object->getType()==T_BreakableBloc)
                {
                    this->game->getMap()->set(NULL,x,y);
                    object->destroy();
                    //créer bonus
                }
                manager->endExplose();
            break;
            case C_Kill:
                //destruction du bonus
            break;
            case C_Block:
                manager->endExplose();
            break;
            case C_Nothing:
                manager->nextExplose();
            break;
        }
        int tmpX=this->player->getTransX();tmpX=tmpX/10-1;
        int tmpY=this->player->getTransY();tmpY=tmpY/10-1;

        if(tmpX==x && tmpY==y)
        {
            //Mort!
            this->player->setVisible(false);
        }
	}

	void Classic::destroyManagerExplosion(ManagerExplosion* manager)
	{
	    delete manager;
	}

	Bomberman* Classic::getPlayer()
	{
	    return player;
	}

	void Classic::setPlayer(Bomberman* bomber)
	{
	    player=bomber;
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
                return this->phase[phaseCurrent-2];
            break;
            case P_Next:
                return this->phase[phaseCurrent+1-2];
            break;
            default:
                return this->phase[phase-2];
            break;
        }
    }

    void Classic::executeAction(Engine::stateEvent &event)
    {
        this->phase[phaseCurrent-2]->executeAction(event);
    }

    void Classic::updateRecv(Socket *socket,const char*s,int size)
    {
        dynamic_cast<PhaseClassic*>(this->phase[phaseCurrent-2])->updateRecv(socket,s,size);
    }
}
