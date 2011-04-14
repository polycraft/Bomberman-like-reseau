#ifndef EXCEPTIONBADRESSOURCE_H
#define EXCEPTIONBADRESSOURCE_H

#include <exception>
#include <string>

namespace Engine
{
class ExceptionBadRessource
{
    public:
        ExceptionBadRessource();
        virtual ~ExceptionBadRessource();
        virtual const char* what() const throw();
    protected:
    private:
};
}
#endif // EXCEPTIONBADRESSOURCE_H
