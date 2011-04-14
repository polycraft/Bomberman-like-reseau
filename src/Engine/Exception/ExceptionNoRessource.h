#ifndef EXCEPTIONNORESSOURCE_H
#define EXCEPTIONNORESSOURCE_H

#include <exception>
#include <string>

namespace Engine
{
class ExceptionNoRessource : public std::exception
{
    public:
        ExceptionNoRessource();
        virtual ~ExceptionNoRessource() throw();
        virtual const char* what() const throw();
};
}
#endif // EXCEPTIONNORESSOURCE_H
