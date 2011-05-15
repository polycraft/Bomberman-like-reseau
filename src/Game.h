#ifndef GAME_H
#define GAME_H
#include "Engine/util/IObserverTimer.h"
#include "Map.h"

class Game : public Engine::IObserverTimer
{
    public:
        Game();
        virtual ~Game();

        void run();
        void updateTimer();

        Map *getMap();
    protected:
    private:
};

#endif // GAME_H
