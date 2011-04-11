#include "ExceptionNoLoader.h"

namespace Engine
{
ExceptionNoLoader::ExceptionNoLoader() throw()
{

}

ExceptionNoLoader::~ExceptionNoLoader() throw()
{
    //dtor
}

const char* ExceptionNoLoader::what() const throw()
{
    return "No loader for this extension";
}

}
