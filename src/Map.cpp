#include "Map.h"



Map::Map(EGameType gameType, int width, int lenght)
{
	this->gameType = gameType;
	this->width = width;
	this->length = lenght;
	Type **temp = new Type*[this->width];
	for(int i=0; i<this->width;i++)
	{
		temp[i]= new Type[this->length];
	}

	this->map = &temp;
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

Scene* Map::getScene(int scene)
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
	return this->length;
}

Type** Map::operator[](int index)
{
	return map[index];
}
