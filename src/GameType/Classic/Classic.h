#ifndef CLASSIC_H
#define CLASSIC_H


#include "../GameType.h"
#include "../../CollisionDetector.h"
#include "../Phase.h"
#include "../../Engine/NetworkEngine/IObserverSocketRecv.h"
#include "../../Engine/EventEngine/IEventListener.h"
#include "../../Type/ManagerExplosion.h"
#include "../../Type/ExplosionFlare.h"
#include "../../Type/Bonus.h"

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
	        P_Dead=4,
	        P_HurryUp=5
	    };
	}

	class Classic : public GameType, public Engine::IObserverSocketRecv,public Engine::IEventListener
	{

	public:
		Classic(Game *game);
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
        void updateRecv(Socket *,Paquet& paquet);

        ManagerFont& getFont();
	private:
		static const int nbBonus=4;
		int partTime;
		CollisionDetector *collision;
		ClassicSpace::EPhase phaseCurrent;
		Bomberman *player;
		vector<Bomberman*> playerNetwork;
		Phase *phase[4];
        ManagerFont font;
	};
}



#endif // CLASSIC_H
