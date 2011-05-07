#ifndef EXCEPTIONUNKNOWHOST_H
#define EXCEPTIONUNKNOWHOST_H

#include <exception>

namespace Engine
{
class ExceptionUnknowHost : public std::exception
{
public:
    ExceptionUnknowHost()throw();
    virtual ~ExceptionUnknowHost() throw();
    virtual const char* what() const throw();
};
}

#endif // EXCEPTIONUNKNOWHOST_H
