#include "LoaderMap.h"


namespace Engine
{
	LoaderMap::LoaderMap()
	{
	}

	LoaderMap::~LoaderMap()
	{
	}

	Ressource* LoaderMap::load(string &name) throw(ExceptionNoFileFound)
	{
		struct SHeader header;
		
		ifstream mapFile(name, ios::in | ios::binary);
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


		Map *map=new Map(header.gameType ,header.width,header.height);

		for( int i=0; i< header.width*header.gameType;i++)
		{
			switch(element[i])
			{
				case 'a':
					map->addObject(new StaticBloc, i/header.width+1, i%header.width );
					break;
				case 'b':
					map->addObject(new BreakableBloc, i/header.width+1, i%header.width);
				break;
				case 'c':
					map->addSpawn(c, i/header.width+1, i%header.width);
				break;

			}
		}
		
		Coordinate c={5,5};


		return map;
	}

	void LoaderMap::free(Ressource &ressource) throw(ExceptionBadRessource)
	{

	}


}