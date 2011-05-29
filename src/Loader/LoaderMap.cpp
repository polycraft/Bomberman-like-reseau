#include "LoaderMap.h"

#include "../Map.h"
#include "../Type/StaticBloc.h"
#include "../Type/BreakableBloc.h"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace Engine;
using namespace std;

LoaderMap::LoaderMap()
{
}

LoaderMap::~LoaderMap()
{
}

Ressource* LoaderMap::load(string &name) throw(ExceptionNoFileFound)
{
    struct SHeader header;

    ifstream mapFile(name.c_str(), ios::in | ios::binary);
    if(!mapFile)
    {
        throw new ExceptionNoFileFound();
    }
    //lit la taille de la map
    mapFile.read((char *) &header, sizeof(struct SHeader));
    //cree le tableau de map
    char *element = new char[header.height*header.width];
    mapFile.read(element, sizeof(char)*header.height*header.width);

    mapFile.close();


    Map *map=new Map(name, header.gameType ,header.width,header.height);

    ///////////////
    char** temp = new char*[header.width];
    for(int x=0; x<header.width;x++)
    {
        temp[x]= new char[header.height];
        for(int y=0;y<header.height;y++)
        {
            temp[x][y] = '0';
        }
    }

    ////////




    for( int i=0; i< header.width*header.height;i++)
    {

        switch(element[i])
        {

            case 'a':
                map->addObject(new StaticBloc(), i%(header.width), header.height - i/(header.width)-1, T_Map );
                temp[i%(header.width)][header.height - i/(header.width)-1]='a';
                break;
            case 'b':
                map->addObject(new BreakableBloc(), i%(header.width), header.height - i/(header.width)-1, T_Dyn);
                temp[i%(header.width)][header.height - i/(header.width)-1]='b';
            break;
            case 'c':
                map->addSpawn(i%(header.width), header.height - i/(header.width)-1);
            break;
        }
    }

    return map;
}

void LoaderMap::free(Ressource &ressource) throw(ExceptionBadRessource)
{

}
