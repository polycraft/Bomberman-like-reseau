#ifndef EXCEPTIONLISTEN_H
#define EXCEPTIONLISTEN_H

#include <exception>

namespace Engine
{
class ExceptionListen : public std::exception
{
public:
    ExceptionListen()throw();
    virtual ~ExceptionListen() throw();
    virtual const char* what() const throw();
};
}

#endif // EXCEPTIONLISTEN_H
