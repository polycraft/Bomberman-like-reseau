#ifndef EXCEPTIONMUTEX_H
#define EXCEPTIONMUTEX_H

#include <exception>

namespace Engine
{
class ExceptionMutex : public std::exception
{
public:
    ExceptionMutex()throw();
    virtual ~ExceptionMutex() throw();
    virtual const char* what() const throw();
};
}

#endif // EXCEPTIONMUTEX_H
