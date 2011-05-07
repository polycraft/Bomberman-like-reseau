#ifndef EXCEPTIONSELECT_H
#define EXCEPTIONSELECT_H

#include <exception>

namespace Engine
{
class ExceptionSelect : public std::exception
{
public:
    ExceptionSelect()throw();
    virtual ~ExceptionSelect() throw();
    virtual const char* what() const throw();
};
}

#endif // EXCEPTIONSELECT_H
