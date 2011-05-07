#include "ExceptionSelect.h"

namespace Engine
{
ExceptionSelect::ExceptionSelect() throw()
{

}

ExceptionSelect::~ExceptionSelect() throw()
{
    //dtor
}

const char* ExceptionSelect::what() const throw()
{
    return "Erreur select";
}

}
