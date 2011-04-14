#include "ExceptionNoRessource.h"

namespace Engine
{
ExceptionNoRessource::ExceptionNoRessource()
{
    //ctor
}

ExceptionNoRessource::~ExceptionNoRessource() throw()
{
    //dtor
}
const char* ExceptionNoRessource::what() const throw()
{
    return "Cette ressource n'est pas chargé";
}
}
