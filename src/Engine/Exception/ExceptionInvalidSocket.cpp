#include "ExceptionInvalidSocket.h"

namespace Engine
{
ExceptionInvalidSocket::ExceptionInvalidSocket() throw()
{

}

ExceptionInvalidSocket::~ExceptionInvalidSocket() throw()
{
    //dtor
}

const char* ExceptionInvalidSocket::what() const throw()
{
    return "Socket invalide";
}

}
