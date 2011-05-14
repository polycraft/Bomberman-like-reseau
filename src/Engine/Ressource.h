#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <string>
#include <exception>
#include "Exception/ExceptionBadRessource.h"

using namespace std;

namespace Engine
{
/**
Type générique des ressources
**/
class Ressource
{
    public:
        /**
        Retourne la ressource chargé
        **/

        Ressource(string &name);

        /**
        Libere la ressource
        **/
        virtual ~Ressource();

        template<class T> static  T* getRessource(Ressource& ressource) throw(ExceptionBadRessource)
        {
            try
            {
                T *res=dynamic_cast<T*>(&ressource);
                return res;
            }
            catch (exception& e)
            {
                throw ExceptionBadRessource();
            }
        }
    private:
        string name;
};
}

#endif // RESSOURCE_H
