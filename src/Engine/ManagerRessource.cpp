#include "ManagerRessource.h"

#include <string>
#include <map>

//Les Loaders
#include "Loader/Loader.h"
#include "Loader/LoaderMusic.h"
#include "Loader/LoaderSample.h"
#include "Loader/LoaderTexture.h"
#include "Loader/LoaderObject.h"
#include "../Loader/LoaderMap.h"

#include "Ressource.h"
#include "Exception/ExceptionNoLoader.h"
#include "Exception/ExceptionNoRessource.h"

using namespace std;

namespace Engine
{
    //Initialisation de l'instance
    ManagerRessource *ManagerRessource::instance = NULL;

    ManagerRessource::ManagerRessource()
    {
        //Initialisation des contenneurs
        //loader=new map<string,Loader*>();
        //ressource= new map<string,Ressource*>();

        //Loader sonore
        Loader *loaderMusic=new LoaderMusic();
        Loader *loaderSample=new LoaderSample();

        _addLoader("mp3",loaderMusic);
        _addLoader("wav",loaderSample);

		//Loader Texture
		Loader *loaderTexture=new LoaderTexture();
		_addLoader("bmp",loaderTexture);
		_addLoader("jpg",loaderTexture);
		_addLoader("png",loaderTexture);
		_addLoader("tga",loaderTexture);
		_addLoader("dds",loaderTexture);

		//loader Objet
		Loader *loaderObject=new LoaderObject();
		_addLoader("obj",loaderObject);
    }

    ManagerRessource::~ManagerRessource()
    {
        //dtor
        //TODO Libérer les loader et les ressources
    }

    void ManagerRessource::addLoader(string extension,Loader *loader)
    {
        //Récupération du manager
        ManagerRessource *manager=getInstance();

        //Ajoute ou remplace le loader suivant l'extension
        manager->_addLoader(extension,loader);
    }

    void ManagerRessource::_addLoader(string extension,Loader *loader)
    {
        //Ajoute ou remplace le loader suivant l'extension
        (this->loader)[extension]=loader;
    }

    void ManagerRessource::freeRessource(string &names,Ressource &ressource)throw(ExceptionNoLoader,ExceptionNoRessource)
    {
        //Récupération du manager
        ManagerRessource *manager=getInstance();

        //Ressource non chargé
        if(manager->ressource.find(names)==manager->ressource.end())
        {
            throw ExceptionNoRessource();
        }
        getLoader(names)->free(ressource);
    }

    Ressource* ManagerRessource::getRessource(string names)throw(ExceptionNoLoader)
    {
        //Récupération du manager
        ManagerRessource *manager=getInstance();

        //Ressource non chargé
        if(manager->ressource.find(names)==manager->ressource.end())
        {
            //Charges et enregistre la ressource avec le bon loader et la retourne
            return (manager->ressource)[names]=getLoader(names)->load(names);
        }
        //Retourne la ressource qui est déjà chargé
        return (manager->ressource)[names] ;
    }

    ManagerRessource* ManagerRessource::getInstance()
    {
        if(instance==NULL)
        {
            instance=new ManagerRessource();
        }
        return instance;
    }

    Loader* ManagerRessource::getLoader(string &name) throw(ExceptionNoLoader)
    {
        //Récupération du manager
        ManagerRessource *manager=getInstance();

        //Récupère l'extension du fichier pour choisir le bon loader
        string extension = name.substr(name.find_last_of(".")+1);

        if(manager->loader.find(extension)==manager->loader.end())
        {
            throw ExceptionNoLoader();
        }
        return (manager->loader)[extension];
    }
}
