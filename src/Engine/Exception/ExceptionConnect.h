#ifndef EXCEPTIONCONNECT_H
#define EXCEPTIONCONNECT_H

#include <exception>

namespace Engine
{
class ExceptionConnect : public std::exception
{
public:
    ExceptionConnect()throw();
    virtual ~ExceptionConnect() throw();
    virtual const char* what() const throw();
};
}

#endif // EXCEPTIONCONNECT_H
