#ifndef EXCEPTIONSEND_H
#define EXCEPTIONSEND_H

#include <exception>

namespace Engine
{
class ExceptionSend : public std::exception
{
public:
    ExceptionSend()throw();
    virtual ~ExceptionSend() throw();
    virtual const char* what() const throw();
};
}
#endif // EXCEPTIONSEND_H
