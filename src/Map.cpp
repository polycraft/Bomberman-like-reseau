#include "Map.h"



Map::Map(EGametype gameType, int width, int lenght)
{
	this->gameType = gameType;
	this->width = width;
	this->length = lenght;
	this->map = new Type[this->width, this->length];
}

Map::~Map()
{
}

void Map::addBOmberman(Bomberman bomberman)
{
}

void Map::addObject(Type type, int x, int y)
{
	this->map[i][j] = type;
}

void Map::addSpawn(int id)
{

}

Scene Map::getScene(int scene)
{
}

coordinate Map::getSpawn(int id)
{
}

int Map::getWidth()
{
	return this->width;
}

int Map::getLength()
{
	return this->length;
}

Type Map::operator[](int index)
{
	return map[][];
}
