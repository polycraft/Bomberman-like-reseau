#include "ExceptionUnknowHost.h"

namespace Engine
{
ExceptionUnknowHost::ExceptionUnknowHost() throw()
{

}

ExceptionUnknowHost::~ExceptionUnknowHost() throw()
{
    //dtor
}

const char* ExceptionUnknowHost::what() const throw()
{
    return "Hote inconnu";
}

}
