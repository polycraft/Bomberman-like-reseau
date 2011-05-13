#include "Map.h"



Map::Map(EGameType gameType, int width, int lenght)
{
	this->gameType = gameType;
	this->width = width;
	this->length = lenght;
	this->map = new Type[this->widt, this->length];
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

void Map::addSpawn(SCoordinate spawn)
{
	this->spawn.push_back(spawn);
}

Scene Map::getScene(int scene)
{
	return this->scene.push_back(scene);
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
