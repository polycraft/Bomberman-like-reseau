#ifndef EXCEPTIONNOENGINE_H
#define EXCEPTIONNOENGINE_H

#include <exception>
#include <string>

namespace Engine
{
class ExceptionNoEngine : public std::exception
{
    public:
        ExceptionNoEngine()throw();
        virtual ~ExceptionNoEngine()throw();
        virtual const char* what() const throw();
};
}

#endif // EXCEPTIONNOENGINE_H
