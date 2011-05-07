#ifndef THREADABLE_H
#define THREADABLE_H

#include <pthread.h>
#include "../Exception/Exception.h"

namespace Engine
{
class Threadable
{
    public:
        Threadable();
        virtual ~Threadable();
        pthread_t &run(bool* stop);
        static void *entryPoint(void*);
    protected:
        void P();
        void V();
        virtual void runThread(bool *stop)=0;
    private:
        pthread_mutex_t mutex;
};

struct Thread
{
    bool* stop;
    Threadable *instance;
};
}

#endif // THREADABLE_H
