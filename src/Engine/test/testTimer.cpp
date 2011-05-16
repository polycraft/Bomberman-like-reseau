#include "testTimer.h"
#include "../util/Timer.h"
#include "../util/Timer.h"

#include <iostream>
#include <string>

using namespace Engine;
using namespace std;

class TestTimer : public IObserverTimer
{
    public:
    TestTimer(const char* s):s(s)
    {
        compteur=0;
    }
    void updateTimer(unsigned int delay)
    {
        compteur++;
        cout << s << " called " << compteur << "times" << endl;
    }
    private:
    string s;
    int compteur;
};

int testTimer()
{
    Timer *timer=Timer::getTimer();

    timer->addListener(new TestTimer("Test1"),2000);
    timer->addListener(new TestTimer("Test2"),10000);
    timer->addListenerOnce(new TestTimer("Test3"),5000);

    while(1)
    {
        timer->update();
    }

}
