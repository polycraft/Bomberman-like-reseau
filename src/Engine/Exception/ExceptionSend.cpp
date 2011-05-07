#include "ExceptionSend.h"

namespace Engine
{
ExceptionSend::ExceptionSend() throw()
{

}

ExceptionSend::~ExceptionSend() throw()
{
    //dtor
}

const char* ExceptionSend::what() const throw()
{
    return "Erreur d'envoie";
}

}
