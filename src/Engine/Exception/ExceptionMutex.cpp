#include "ExceptionMutex.h"

namespace Engine
{
ExceptionMutex::ExceptionMutex() throw()
{

}

ExceptionMutex::~ExceptionMutex() throw()
{
    //dtor
}

const char* ExceptionMutex::what() const throw()
{
    return "Erreur de mutex";
}

}
