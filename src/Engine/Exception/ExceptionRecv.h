#ifndef EXCEPTIONRECV_H
#define EXCEPTIONRECV_H

#include <exception>

namespace Engine
{
class ExceptionRecv : public std::exception
{
public:
    ExceptionRecv()throw();
    virtual ~ExceptionRecv() throw();
    virtual const char* what() const throw();
};
}

#endif // EXCEPTIONRECV_H
