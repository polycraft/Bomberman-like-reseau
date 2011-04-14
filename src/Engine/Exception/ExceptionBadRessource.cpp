#include "ExceptionBadRessource.h"

namespace Engine
{
ExceptionBadRessource::ExceptionBadRessource()
{
    //ctor
}

ExceptionBadRessource::~ExceptionBadRessource()
{
    //dtor
}
const char* ExceptionBadRessource::what() const throw()
{
    return "Bad type for this ressource";
}

}
