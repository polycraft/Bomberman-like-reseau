#include "Threadable.h"


namespace Engine
{
Threadable::Threadable()
{
    hasRun=false;
}

Threadable::~Threadable()
{
    if(hasRun)
    {
        if (pthread_mutex_destroy(&(mutex)))
        {
            pthread_exit(NULL);
            throw ExceptionMutex();
        }
    }
}

Thread *Threadable::run(bool* stop)
{
    Thread *thread=new Thread;
    thread->instance=this;
    thread->stop=stop;

    if(!hasRun)
    {
        hasRun=true;
        if (pthread_mutex_init(&(mutex), NULL))
        {
            pthread_exit(NULL);
            throw ExceptionMutex();
        }
    }

    pthread_t *t=new pthread_t;
    thread->t=t;

    pthread_create (t, NULL, Threadable::entryPoint, (void*)thread);



    return thread;
}

void* Threadable::entryPoint(void* arg)
{
    Thread *t=(Thread*)arg;
    t->instance->runThread(t->stop);

    delete t->t;
    delete t;
}

void Threadable::P()
{
    if (pthread_mutex_lock(&(mutex)))
    {
        pthread_exit(NULL);
        throw ExceptionMutex();
    }
}

void Threadable::V()
{
    if (pthread_mutex_unlock(&(mutex)))
    {
        pthread_exit(NULL);
        throw ExceptionMutex();
    }
}

void Threadable::join(struct Thread* t)
{
    pthread_join( *(t->t), NULL);
}
}

