#ifndef EXCEPTIONINVALIDSOCKET_H
#define EXCEPTIONINVALIDSOCKET_H

#include <exception>

namespace Engine
{
class ExceptionInvalidSocket : public std::exception
{
public:
    ExceptionInvalidSocket()throw();
    virtual ~ExceptionInvalidSocket() throw();
    virtual const char* what() const throw();
};
}

#endif // EXCEPTIONINVALIDSOCKET_H
