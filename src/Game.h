#ifndef GAME_H
#define GAME_H

#include "Engine/util/IObserverTimer.h"
#include "Engine/MainEngine.h"
#include "Engine/NetworkEngine/IObserverSocketRecv.h"

class Map;

class Game : public Engine::IObserverTimer, public Engine::IObserverSocketRecv
{
    public:
        Game();
        virtual ~Game();

        void run();
        void updateTimer(unsigned int delay);

        Map *getMap();
        Engine::MainEngine* getEngine();
        void updateRecv(Engine::Socket *,Engine::Paquet& paquet);
    protected:
    private:
    Map *map;
    Engine::MainEngine* engine;
};

#endif // GAME_H
