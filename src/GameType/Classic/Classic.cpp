#include "Classic.h"

#include "../../Type/ManagerExplosion.h"
#include "../../Type/ExplosionFlare.h"
#include "../../Game.h"
#include "../../Map.h"
#include "../../CollisionDetector.h"
#include "../../Type/Bomb.h"
#include "../../Type/Bomberman.h"

#include "Initialisation.h"
#include "Running.h"
#include "HurryUp.h"
#include "Dead.h"
#include "Ending.h"

using namespace Engine;

namespace GameTypeSpace
{
    using namespace ClassicSpace;

	Classic::Classic(Game *game, Engine::Socket *socket, int idBomber):GameType(game,10, socket),font("src/ressource/font/font.ttf",24)
	{
		srand ( time(NULL) );
		this->player = new Bomberman(idBomber);
	    phaseCurrent=P_Initialisation;

	    collision=new CollisionDetector(game->getMap());

	    phase[P_Initialisation-2]=new Initialisation(this,collision, idBomber);
	    phase[P_Running-2]=new Running(this,collision);
	    phase[P_Dead-2]=new Dead(this,collision);
	    phase[P_HurryUp-2]=new HurryUp(this,collision);
        phase[P_Ending-2]=new Ending(this,collision);


        game->getEngine()->getGengine()->getManagerText().addFont(&font);

	    this->game->getEngine()->getEventEngine()->addListener(this);
	}

	Classic::~Classic()
	{
	    delete collision;
	    delete phase[P_Initialisation-2];
	    delete phase[P_Running-2];
	    delete phase[P_HurryUp-2];
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

	    int tmpX=bomb->getTransX();tmpX=tmpX/10-1;
	    int tmpY=bomb->getTransY();tmpY=tmpY/10-1;

	    this->game->getMap()->set(NULL,tmpX,tmpY);

	    new ManagerExplosion(tmpX,tmpY,bomb->getIdOwner(), speed, power, this);
	}

	void Classic::updateExplosion(ExplosionFlare *flare,int power,int x,int y)
	{
	    if(flare->getType()==T_Emitter)
	    {
	        flare->endExplose();
	    }
	    else
	    {
            switch(flare->getType())
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
                default:

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
						//créer bonus=> remplace la caisse
						/*EBonus random = this->randomBonus();
						if(random != T_None)
						{
								this->game->getMap()->addObject(new Bonus(random),x,y,T_Map);
						}
						else this->game->getMap()->set(NULL,x,y);
                        object->destroy();*/

                    }
                    flare->endExplose();
                break;
                case C_Kill:
					object=this->game->getMap()->get(x,y);
                    this->game->getMap()->set(NULL,x,y);
					object->destroyTimeAnim();
					object->destroy();
					flare->nextExplose();
                break;
                case C_Block:
                    flare->endExplose();
                break;
                case C_Nothing:
                    flare->nextExplose();
                break;
                default:

                break;
            }
	    }
	}

	EBonus Classic::randomBonus()
	{
		  return (EBonus)(rand() % this->nbBonus);
	}

	void Classic::destroyManagerExplosion(ManagerExplosion* manager)
	{
	    delete manager;
	    player->setProperty<int>(PB_nbBomb,player->getProperty<int>(PB_nbBomb)+1);
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

    void Classic::updateRecv(Socket *socket,Paquet& paquet)
    {
        dynamic_cast<PhaseClassic*>(this->phase[phaseCurrent-2])->updateRecv(socket,paquet);
		char type=(paquet.getData())[0];
		switch(type)
		{
			case 'b'://Bombe
			{
				PaquetBomb *paquetBomb=paquet.getData<PaquetBomb*>();
				Bomb* bomb=new Bomb(
                                    this,
                                    paquetBomb->idBomber,
									paquetBomb->explodeTime,
									paquetBomb->vitesseExplode,
									paquetBomb->power);
				this->getGame()->getMap()->addObject(bomb,paquetBomb->x,paquetBomb->y,T_Dyn);

				this->getPlayer()->setProperty<int>(PB_nbBomb,this->getPlayer()->getProperty<int>(PB_nbBomb)-1);
			}
			break;
			case 'm'://Movements
			{
				PaquetMove *paquetMove=paquet.getData<PaquetMove*>();

				//On cherche le Bomberman concerné
				vector<Bomberman*>::iterator it;

                for ( it=playerNetwork.begin() ; it < playerNetwork.end(); it++ )
                {
                    if((*it)->getProperty<int>(PB_id)==paquetMove->idBomber)
                    {
                        //On le déplace
                        (*it)->setTransX(paquetMove->x);
                        (*it)->setTransY(paquetMove->y);
                        (*it)->setRotation(0,0,paquetMove->rotation);
                    }
                }
			}
			break;
			case 'u': //Bonus
			{
				PaquetBonus *paquetBonus=paquet.getData<PaquetBonus*>();
				//obtiens lobjet deja présent
				Object *object = this->game->getMap()->get(paquetBonus->x,paquetBonus->y);

				EBonus typeBonus = static_cast<EBonus>(paquetBonus->bonus);
				if(typeBonus != T_None)
				{
					//remplace la caisse
					this->game->getMap()->addObject(new Bonus(typeBonus),paquetBonus->x,paquetBonus->y,T_Map);
				}
				else this->game->getMap()->set(NULL,paquetBonus->x,paquetBonus->y);
                object->destroy();
			}
			break;
            case 'p':
            {
                PaquetPhase *paquetPhase=paquet.getData<PaquetPhase*>();
                phaseCurrent = static_cast<EPhase>(paquetPhase->phase);
            }
            break;
		}

    }

    ManagerFont& Classic::getFont()
    {
        return font;
    }

	void Classic::updateTimer(unsigned int delay)
	{
		if(delay == this->timeServerMovement)
		{
			PaquetMove paquetMove={'m', Engine::Timer::getTimer()->getTime(),
				this->player->getProperty<int>(PB_id),
				this->player->getTransX(),
				this->player->getTransY(),
				this->player->getRotateZ()
				};
			this->socket->sendData<PaquetMove>(&paquetMove);
		}
	}

	int Classic::getTimeServMove()
	{
		return this->timeServerMovement;
	}
}
