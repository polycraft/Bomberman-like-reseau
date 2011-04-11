#include "ManagerRessource.h"

#include <string>
#include <map>

#include "Loader/Loader.h"
#include "Ressource.h"
#include "Exception/ExceptionNoLoader.h"

using namespace std;

namespace Engine
{
    ManagerRessource::ManagerRessource()
    {
        //ctor
    }

    ManagerRessource::~ManagerRessource()
    {
        //dtor
    }

    void ManagerRessource::addLoader(string &extension,Loader *loader)
    {
        //Récupération du manager
        ManagerRessource *manager=getInstance();

        //Ajoute ou remplace le loader suivant l'extension
        (*(manager->loader))[extension]=loader;
    }

    Ressource& ManagerRessource::getRessource(string &names)
    {
        //Récupération du manager
        ManagerRessource *manager=getInstance();

        //Ressource non chargé
        if(manager->ressource->find(names)==manager->ressource->end())
        {
            //Récupère l'extension du fichier pour choisir le bon loader
            string extension = names.substr(names.find_last_of(".")+1);

            if(manager->loader->find(extension)==manager->loader->end())
            {
                throw ExceptionNoLoader();
            }

            //Charges et enregistre la ressource avec le bon loader et la retourne
            return *( (*(manager->ressource))[names]=(*(manager->loader))[extension]->load(names) );
        }
        //Retourne la ressource qui est déjà chargé
        return *( (*(manager->ressource))[names] );
    }

    ManagerRessource* ManagerRessource::getInstance()
    {
        if(instance==NULL)
        {
            instance=new ManagerRessource();
        }
        return instance;
    }
}
