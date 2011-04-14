#include "ExceptionNoFileFound.h"

namespace Engine
{
ExceptionNoFileFound::ExceptionNoFileFound() throw()
{

}

ExceptionNoFileFound::~ExceptionNoFileFound() throw()
{
    //dtor
}

const char* ExceptionNoFileFound::what() const throw()
{
    return "File not found";
}

}

