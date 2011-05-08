#include "testThreadable.h"
#include "../util/Threadable.h"
#include <stdio.h>

using namespace Engine;

class testThread : public Threadable
{
    public:
    testThread(int time,int nb)
    {
        this->time=time;
        this->nb=nb;
    }

    void runThread(bool *stop)
    {
        int i=0;
        while(!*stop)
        {
            sleep(time);
            printf("%d %d\n",nb,i);
            i++;
            if(i==10)
                *stop=true;
        }
    }
    private:
        int time;
        int nb;
};

int testThreadable()
{
    bool stop=false;

    testThread t1(1,1);
    //testThread t2(1,2);

    Thread *tr=t1.run(&stop);
    Thread *tr1=t1.run(&stop);

    while(!stop)
    {
        sleep(1);
        printf("j'attend..\n");
    }
    Threadable::join(tr);
    Threadable::join(tr1);
}
