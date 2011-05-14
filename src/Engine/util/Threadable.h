#ifndef THREADABLE_H
#define THREADABLE_H

#include <pthread.h>
#include <vector>
#include "../Exception/Exception.h"

using namespace std;

namespace Engine
{
    struct Thread;
class Threadable
{
    public:
        Threadable();
        virtual ~Threadable();
        struct Thread *run(bool* stop);
        void stop();
        static void *entryPoint(void*);
        static void join(struct Thread*);
    protected:
        void P();
        void V();
        void initMutex(pthread_mutex_t &mutex);
        void stopMutex(pthread_mutex_t &mutex);
        void P(pthread_mutex_t &mutex);
        void V(pthread_mutex_t &mutex);
        virtual void runThread(bool *stop)=0;
        bool hasRun;
    private:
        pthread_mutex_t mutex;
        vector<struct Thread *> threads;
};

typedef struct Thread
{
    bool* stop;
    Threadable *instance;
    pthread_t *t;
} Thread;
}

#endif // THREADABLE_H
