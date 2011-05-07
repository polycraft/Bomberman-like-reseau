#ifndef EXCEPTIONBADRESSOURCE_H
#define EXCEPTIONBADRESSOURCE_H

#include <exception>
#include <string>

namespace Engine
{
class ExceptionBadRessource : public std::exception
{
    public:
        ExceptionBadRessource()throw();
        virtual ~ExceptionBadRessource()throw();
        virtual const char* what() const throw();
};
}
#endif // EXCEPTIONBADRESSOURCE_H
