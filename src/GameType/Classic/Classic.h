#ifndef CLASSIC_H
#define CLASSIC_H

#include "../../Type/Paquet.h"
#include "../../Engine/NetworkEngine/IObserverSocketRecv.h"
#include "../../Engine/EventEngine/IEventListener.h"
#include "../../Engine/GraphicEngine/Text/ManagerFont.h"
#include "../GameType.h"
#include "../Phase.h"
#include "../../Type/Bonus.h"
#include "../../Engine/NetworkEngine/Socket.h"

class CollisionDetector;
class Game;
class Bomberman;
class Bomb;
class ExplosionFlare;
class ManagerExplosion;



namespace GameTypeSpace
{
	namespace ClassicSpace
	{
	    typedef enum EPhase
	    {
	        P_Current=0,
	        P_Next=1,
	        P_Initialisation=2,
	        P_Running=3,
	        P_HurryUp=4,
			P_Ending=5,
			P_Dead=6
	    } EPhase;
	}

	class Classic : public GameType, public Engine::IObserverSocketRecv,public Engine::IEventListener
	{

	public:
		Classic(Game *game, Engine::Socket *socket, int idBomber);
		virtual ~Classic();
		void update();


		Bomberman* getPlayer();
		void setPlayer(Bomberman*);
		vector<Bomberman*>& getPlayerNetwork();

        Phase* getPhase(ClassicSpace::EPhase phase);

        virtual void explode(Bomb* bomb,int speed,int power);
		void updateExplosion(ExplosionFlare *flare,int power,int x,int y);
        void destroyManagerExplosion(ManagerExplosion* manager);
		EBonus randomBonus();

        void executeAction(Engine::stateEvent &event);
        void updateRecv(Engine::Socket *,Engine::Paquet& paquet);
		void updateTimer(unsigned int delay);

		int getTimeServMove();

        Engine::ManagerFont& getFont();
	private:
		static const int timeServerMovement = 100;
		static const int nbBonus=4;
		int partTime;
		CollisionDetector *collision;
		ClassicSpace::EPhase phaseCurrent;
		Bomberman *player;
		vector<Bomberman*> playerNetwork;
		Phase *phase[4];
        Engine::ManagerFont font;
	};
}



#endif // CLASSIC_H
