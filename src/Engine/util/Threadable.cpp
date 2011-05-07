#include "Threadable.h"


namespace Engine
{
Threadable::Threadable()
{
    //ctor
}

Threadable::~Threadable()
{
    if (pthread_mutex_destroy(&(mutex)))
    {
        pthread_exit(NULL);
        throw ExceptionMutex();
    }
}

pthread_t &Threadable::run(bool* stop)
{
    pthread_t threads;
    Thread thread= {stop,this};

    if (pthread_mutex_init(&(mutex), NULL))
    {
        pthread_exit(NULL);
        throw ExceptionMutex();
    }

    pthread_create (&threads, NULL, Threadable::entryPoint, (void*)&thread);

    return threads;
}

void* Threadable::entryPoint(void* arg)
{
    struct Thread *t=(struct Thread*)arg;
    t->instance->runThread(t->stop);
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
}

