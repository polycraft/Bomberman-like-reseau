#ifndef GAME_H
#define GAME_H
#include "Engine/util/IObserverTimer.h"
#include "Map.h"
#include "Engine/MainEngine.h"
#include "Engine/NetworkEngine/IObserverSocketRecv.h"


class Game : public Engine::IObserverTimer, public Engine::IObserverSocketRecv
{
    public:
        Game();
        virtual ~Game();

        void run();
        void updateTimer(unsigned int delay);

        Map *getMap();
        MainEngine* getEngine();
        void updateRecv(Socket *,Paquet& paquet);
    protected:
    private:
    Map *map;
    MainEngine* engine;
};

#endif // GAME_H
