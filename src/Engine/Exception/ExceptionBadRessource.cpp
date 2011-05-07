#include "ExceptionBadRessource.h"

namespace Engine
{
ExceptionBadRessource::ExceptionBadRessource() throw()
{
    //ctor
}

ExceptionBadRessource::~ExceptionBadRessource() throw()
{
    //dtor
}
const char* ExceptionBadRessource::what() const throw()
{
    return "Bad type for this ressource";
}

}
