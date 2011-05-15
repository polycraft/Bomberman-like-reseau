#include "Map.h"



Map::Map(string &name, EGameType gameType, int width, int height)  : Ressource(name)
{
	this->gameType = gameType;
	this->width = width;
	this->height = height;
	Type ***temp = new Type**[this->height];
	for(int i=0; i<this->height;i++)
	{
		temp[i]= new Type*[this->width];
		for(int j=0;j<height;j++)
		{
			temp[i][j] = NULL;
		}
	}

	this->map = temp;
}

Map::~Map()
{
}

void Map::addBomberman(Bomberman bomberman)
{
}

void Map::addObject(Type* object, int x, int y)
{
	this->map[x][y] = object;
}

void Map::addSpawn(int x, int y)
{
	SCoordinate temp;
	temp.x=x;
	temp.y=y;
	this->spawn.push_back(temp);
}

Scene* Map::getScene(EScene scene)
{
	return this->scene[scene];
}

SCoordinate Map::getSpawn(int id)
{
	return this->spawn[id];
}

int Map::getWidth()
{
	return this->width;
}

int Map::getLength()
{
	return this->height;
}

Type* Map::get(int x,int y)
{
	return map[x][y];
}

void Map::setEngine(MainEngine *engine)
{
	this->engine = engine;
	buildScenes();
	this->engine->getGengine()->addScene(this->scene[T_World]);
	this->engine->getGengine()->addScene(this->scene[T_Map]);


}

void Map::buildScenes()
{
	//Scene World
	this->scene.push_back(new Scene(Engine::TS_Static));
	double x0,y0,z0;
	x0=y0=5;
	z0=-5;
	double z1=z0+10;//repere des bords
	for(int i=0; i< height+2; i++)
	{
		for(int j=0; j<width+2; j++)
		{
			if(i==0 || i==height+2-1)
			{
				StaticBloc *temp1 = new StaticBloc();
				temp1->setCoordonnes(j*10+x0,i*10+y0,z1);
				this->scene[T_World]->addObject(temp1);
			}
			else if((j==0) || j==width+2-1)
			{
				StaticBloc *temp1 = new StaticBloc();
				temp1->setCoordonnes(j*10+x0,i*10+y0,z1);
				this->scene[T_World]->addObject(temp1);
			}
			StaticBloc *temp0 = new StaticBloc();
			temp0->setCoordonnes(j*10+x0,i*10+y0,z0);
			this->scene[T_World]->addObject(temp0);
		}
	}



	//Scene Map
	this->map[0][1];
	this->scene.push_back(new Scene(Engine::TS_Static));
	double x1=x0+10;
	double y1=y0+10;
	
	for(int i=0; i<height;i++)
	{
		for(int j=0; j<width; j++)
		{
			if(this->map[i][j] != NULL)
			{
				switch(this->map[i][j]->getType())
				{
					case T_StaticBloc:
						StaticBloc *temp = new StaticBloc();
						temp->setCoordonnes(j*10+x1,i*10+y1,z1);
						temp->getData()->setTexture(ManagerRessource::getRessource<Texture>("src/ressource/texture/dirt.jpg"));
						this->scene[T_Map]->addObject(temp);
						break;
				}
			}
		}
	}


	//Scene dynamique
	this->scene.push_back(new Scene(Engine::TS_Dynamique));





}