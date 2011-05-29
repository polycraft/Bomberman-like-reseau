#include "ExceptionInitSocket.h"

namespace Engine
{
ExceptionInitSocket::ExceptionInitSocket() throw()
{

}

ExceptionInitSocket::~ExceptionInitSocket() throw()
{
    //dtor
}

const char* ExceptionInitSocket::what() const throw()
{
    return "Erreur Init Socket";
}

}
