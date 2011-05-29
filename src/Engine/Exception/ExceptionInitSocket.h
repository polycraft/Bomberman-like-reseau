#ifndef EXCEPTIONINITSOCKET_H
#define EXCEPTIONINITSOCKET_H

#include <exception>

namespace Engine
{
class ExceptionInitSocket : public std::exception
{
public:
    ExceptionInitSocket()throw();
    virtual ~ExceptionInitSocket() throw();
    virtual const char* what() const throw();
};
}

#endif // EXCEPTIONINITSOCKET_H
