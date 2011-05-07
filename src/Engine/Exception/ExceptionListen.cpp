#include "ExceptionListen.h"

namespace Engine
{
ExceptionListen::ExceptionListen() throw()
{

}

ExceptionListen::~ExceptionListen() throw()
{
    //dtor
}

const char* ExceptionListen::what() const throw()
{
    return "Erreur listen";
}

}
