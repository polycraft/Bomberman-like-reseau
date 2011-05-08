#ifndef THREADABLE_H
#define THREADABLE_H

#include <pthread.h>
#include "../Exception/Exception.h"

namespace Engine
{
    struct Thread;
class Threadable
{
    public:
        Threadable();
        virtual ~Threadable();
        struct Thread *run(bool* stop);
        static void *entryPoint(void*);
        static void join(struct Thread*);
    protected:
        void P();
        void V();
        virtual void runThread(bool *stop)=0;
        bool hasRun;
    private:
        pthread_mutex_t mutex;
};

typedef struct Thread
{
    bool* stop;
    Threadable *instance;
    pthread_t *t;
} Thread;
}

#endif // THREADABLE_H
