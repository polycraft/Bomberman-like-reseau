#include "ExceptionConnect.h"

namespace Engine
{
ExceptionConnect::ExceptionConnect() throw()
{

}

ExceptionConnect::~ExceptionConnect() throw()
{
    //dtor
}

const char* ExceptionConnect::what() const throw()
{
    return "Erreur listen";
}

}
