#include "ExceptionNoEngine.h"

namespace Engine
{
ExceptionNoEngine::ExceptionNoEngine() throw()
{
    //ctor
}

ExceptionNoEngine::~ExceptionNoEngine() throw()
{
    //dtor
}
const char* ExceptionNoEngine::what() const throw()
{
    return "Engine not load.";
}

}
