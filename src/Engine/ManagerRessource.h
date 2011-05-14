#ifndef MANAGERRESSOURCE_H
#define MANAGERRESSOURCE_H

#include <string>
#include <map>

#include "Loader/Loader.h"
#include "Ressource.h"
#include "Exception/ExceptionNoLoader.h"
#include "Exception/ExceptionNoRessource.h"

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
        static void addLoader(string extension,Loader *loader);

        /**
        Récupère une ressource. Si la ressource n'existe pas elle est créé
        **/
        static Ressource* getRessource(string names)throw(ExceptionNoLoader);

        template<class T> static  T* getRessource(string names)throw(ExceptionNoLoader,ExceptionBadRessource)
        {
            //Récupération du manager
            ManagerRessource *manager=getInstance();

            Ressource *tmp;

            //Ressource non chargé
            if(manager->ressource.find(names)==manager->ressource.end())
            {
                //Charges et enregistre la ressource avec le bon loader et la retourne
                tmp=(manager->ressource)[names]=getLoader(names)->load(names);
            }
            else
            {
                tmp=(manager->ressource)[names] ;
            }


            //Retourne la ressource qui est déjà chargé
            return Ressource::getRessource<T>(*tmp);
        }


        /**
        Libere une ressource en utilisant sont loader
        **/
        static void freeRessource(string &names,Ressource &ressource)throw(ExceptionNoLoader,ExceptionNoRessource);

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
        map<string,Loader*> loader;

        /**
        Tableau des ressources déjà chargé
        Chaque ressource est identifié par un nom de fichier
        **/
        map<string,Ressource*> ressource;
        ManagerRessource();//singleton privé

        /**
        Récupère l'instance de la classe
        **/
        static ManagerRessource *getInstance();

        /**
        Récupere le loader suivant le fichier
        **/
        static Loader* getLoader(string &name) throw(ExceptionNoLoader);

        /**
        Ajoute un chargeur pour une extension
        **/
        void _addLoader(string extension,Loader *loader);
};

}
#endif // MANAGERRESSOURCE_H
