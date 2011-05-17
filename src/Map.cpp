#include "Map.h"



Map::Map(string &name, EGameType gameType, int width, int height)  : Ressource(name)
{
	this->gameType = gameType;
	this->width = width;
	this->height = height;
	Type ***temp = new Type**[this->width];
	for(int x=0; x<this->width;x++)
	{
		temp[x]= new Type*[this->height];
		for(int y=0;y<height;y++)
		{
			temp[x][y] = NULL;
		}
	}

	this->map = temp;

		//Scene World
	this->scene.push_back(new Scene(Engine::TS_Static));
	//Scene Map
	this->scene.push_back(new Scene(Engine::TS_Static));
	//Scene dynamique
	this->scene.push_back(new Scene(Engine::TS_Dynamique));
}

Map::~Map()
{
}

void Map::addBomberman(Bomberman *bomberman,SCoordinate coord)
{
	double x1,y1,z1;
	x1=15;
	y1=15;
	z1=0;

	bomberman->setCoordonnes(coord.x*10+x1,coord.y*10+y1,z1);
	this->scene[T_Dyn]->addObject(bomberman);
}

void Map::addObject(Type* object, int x, int y,EScene scene)
{
	double x1,y1,z1;
	x1=15;
	y1=15;
	z1=5;

	this->map[x][y] = object;
	object->setCoordonnes(x*10+x1,y*10+y1,z1);
	this->scene[scene]->addObject(object);
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

int Map::getHeight()
{
	return this->height;
}

Type* Map::get(int x,int y)
{
	return map[x][y];
}

void Map::set(Type* object,int x,int y)
{
    map[x][y]=object;
}

void Map::setEngine(MainEngine *engine)
{
	this->engine = engine;
	buildScenes();
	this->engine->getGengine()->addScene(this->scene[T_World]);
	this->engine->getGengine()->addScene(this->scene[T_Map]);
	this->engine->getGengine()->addScene(this->scene[T_Dyn]);


}

void Map::buildScenes()
{



	double x0,y0,z0;
	x0=y0=5;
	z0=-5;
	double z1=z0+10;//repere des bords
	for(int x=0; x< width+2; x++)
	{
		for(int y=0; y<height+2; y++)
		{
			if(x==0 || x==width+2-1)
			{
				StaticBloc *temp1 = new StaticBloc();
				temp1->setCoordonnes(x*10+x0,y*10+y0,z1);
				temp1->setTexture(ManagerRessource::getRessource<Texture>("src/ressource/texture/wall.jpg"));
				this->scene[T_World]->addObject(temp1);
			}
			else if((y==0) || y==height+2-1 )
			{
				StaticBloc *temp1 = new StaticBloc();
				temp1->setCoordonnes(x*10+x0,y*10+y0,z1);
				temp1->setTexture(ManagerRessource::getRessource<Texture>("src/ressource/texture/wall.jpg"));
				this->scene[T_World]->addObject(temp1);
			}
			StaticBloc *temp0 = new StaticBloc();
			temp0->setCoordonnes(x*10+x0,y*10+y0,z0);
			temp0->setTexture(ManagerRessource::getRessource<Texture>("src/ressource/texture/grass.jpg"));
			this->scene[T_World]->addObject(temp0);
		}
	}



	//skybox test

	Object *skybox= new Object();
	skybox->attach(ManagerRessource::getRessource<Model>("src/ressource/object/skybox.obj"),ManagerRessource::getRessource<Texture>("src/ressource/texture/skybox2.jpg"));
	skybox->setCoordonnes((width*10)/2,(height*10)/2,0);
	skybox->scale(200,200,200);
	this->scene[T_World]->addObject(skybox);




}
