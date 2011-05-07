#ifndef EXCEPTIONNOLOADER_H
#define EXCEPTIONNOLOADER_H

#include <exception>

namespace Engine
{
class ExceptionNoLoader : public std::exception
{
    public:
        ExceptionNoLoader()throw();
        virtual ~ExceptionNoLoader() throw();
        virtual const char* what() const throw();
};
}
#endif // EXCEPTIONNOLOADER_H
