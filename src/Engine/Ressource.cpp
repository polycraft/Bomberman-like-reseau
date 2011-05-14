#include "Ressource.h"
#include <string>
#include "ManagerRessource.h"

namespace Engine
{

Ressource::Ressource(std::string &name)
{
    this->name=name;
}

Ressource::~Ressource()
{
    ManagerRessource::freeRessource(name,*this);
}

}
