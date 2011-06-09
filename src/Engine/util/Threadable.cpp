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
        hasRun=false;
    }
}

void Threadable::stop()
{
    for (vector<Thread*>::iterator it = threads.begin(); it!=threads.end(); ++it)
    {
         Threadable::join(*it);
    }
    /*for (vector<Thread*>::iterator it = threads.begin(); it!=threads.end(); ++it)
    {
        if(*it!=NULL)
            Threadable::join(*it);
    }*/
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

    threads.push_back(thread);

    return thread;
}

void* Threadable::entryPoint(void* arg)
{
    Thread *t=(Thread*)arg;
    t->instance->runThread(t->stop);

    vector<Thread*>::iterator it;

    for (it = t->instance->threads.begin(); it!=t->instance->threads.end(); ++it)
    {
        if(*it==t)
        {
            t->instance->threads.erase(it);
            break;
        }
    }

	return NULL;
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

void Threadable::initMutex(pthread_mutex_t &mutex)
{
    if (pthread_mutex_init(&(mutex), NULL))
    {
        pthread_exit(NULL);
        throw ExceptionMutex();
    }
}

void Threadable::stopMutex(pthread_mutex_t &mutex)
{

    if (pthread_mutex_destroy(&(mutex)))
    {
        pthread_exit(NULL);
        throw ExceptionMutex();
    }
}


void Threadable::P(pthread_mutex_t &mutex)
{
    if (pthread_mutex_lock(&(mutex)))
    {
        pthread_exit(NULL);
        throw ExceptionMutex();
    }
}

void Threadable::V(pthread_mutex_t &mutex)
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
    delete t->t;
    delete t;
}
}


