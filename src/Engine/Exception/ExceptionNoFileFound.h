#ifndef EXCEPTIONNOFILEFOUND_H
#define EXCEPTIONNOFILEFOUND_H

#include <exception>
#include <string>

namespace Engine
{
class ExceptionNoFileFound : public std::exception
{
    public:
        ExceptionNoFileFound()throw();
        virtual ~ExceptionNoFileFound() throw();
        virtual const char* what() const throw();
};
}
#endif // EXCEPTIONNOFILEFOUND_H

