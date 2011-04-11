#ifndef MANAGERRESSOURCE_H
#define MANAGERRESSOURCE_H

#include <string>
#include <map>

#include "Loader/Loader.h"
#include "Ressource.h"

//Macro permettant d'obtenir la ressource de son type
//Utilisation ManagerRessource_getRessource("mon_model.obj",Model)
#define ManagerRessource_getRessource(names,Class) dynamic_cast<Class>(ManagerRessource::getRessource(names))

using namespace std;

namespace Engine
{

/**
Gestion de toutes les ressources à charger durant l'execution du programme
Classe de type singleton privé
**/
class ManagerRessource
{
    public:
        /**
        Ajoute un chargeur pour une extension
        **/
        static void addLoader(string &extension,Loader *loader);

        /**
        Récupère une ressource. Si la ressource n'existe pas elle est créé
        **/
        static Ressource& getRessource(string &names);

        virtual ~ManagerRessource();
    private:
        /**
        Instance du singleton
        **/
        static ManagerRessource *instance;
        static ManagerRessource *_singleton;

        /**
        Tableau des chargeurs.
        Chaque chargeur est identifié par une extension
        **/
        map<string,Loader*> *loader;

        /**
        Tableau des ressources déjà chargé
        Chaque ressource est identifié par un nom de fichier
        **/
        map<string,Ressource*> *ressource;
        ManagerRessource();//singleton privé

        /**
        Récupère l'instance de la classe
        **/
        static ManagerRessource *getInstance();
};
//Initialisation de l'instance
ManagerRessource *ManagerRessource::instance = NULL;
}
#endif // MANAGERRESSOURCE_H
