#ifndef CLASSIC_H
#define CLASSIC_H

#include "../GameType.h"
#include "../../CollisionDetector.h"
#include "../Phase.h"
#include "../../Engine/NetworkEngine/IObserverSocketRecv.h"
#include "../../Engine/EventEngine/IEventListener.h"
#include "../../Type/ManagerExplosion.h"

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
	        P_HurryUp=4
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
        void updateExplosion(ManagerExplosion *manager,int power,int x,int y);
        void destroyManagerExplosion(ManagerExplosion* manager);

        void executeAction(Engine::stateEvent &event);
        void updateRecv(Socket *,const char*,int size);
	private:
		int partTime;
		CollisionDetector *collision;
		ClassicSpace::EPhase phaseCurrent;
		Bomberman *player;
		vector<Bomberman*> playerNetwork;
		Phase *phase[3];

	};
}



#endif // CLASSIC_H
