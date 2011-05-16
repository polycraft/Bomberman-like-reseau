#ifndef CLASSIC_H
#define CLASSIC_H

#include "../GameType.h"
#include "../../CollisionDetector.h"
#include "../Phase.h"

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

	class Classic : public GameType
	{

	public:
		Classic(Game *game);
		virtual ~Classic();
		void update();
		virtual void explode(Bomb* bomb,int speed,int power);

		Bomberman* getPlayer();
		void setPlayer(Bomberman*);
		vector<Bomberman*>& getPlayerNetwork();

        Phase* getPhase(ClassicSpace::EPhase phase);
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
