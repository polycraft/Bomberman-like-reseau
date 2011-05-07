#include "ExceptionRecv.h"

namespace Engine
{
ExceptionRecv::ExceptionRecv() throw()
{

}

ExceptionRecv::~ExceptionRecv() throw()
{
    //dtor
}

const char* ExceptionRecv::what() const throw()
{
    return "Erreur de reception";
}

}
