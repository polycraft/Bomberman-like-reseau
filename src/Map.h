#ifndef MAP_H
#define MAP_H


#include "Type.h"
#include <vector>
#include "Engine\GraphicEngine\Scene.h"

enum EGameType{
	StaticBloc,
	BreakableBloc
};

struct SCoordinate
{

}

class Map
{

public:
	Map(EGametype gameType, int width, int lenght);
	~Map();
	void addBomberman(Bomberman bomberman);
	void addObject(Type object, int x, int y);
	void addSpawn(SCoordinate spawn);
	Scene getScene(int scene);
	SCoordinate getSpawn(int id);
	int getWidth();
	int getLength();
	Type operator[] (int index);

private:
	int gameType;
	int width;
	int length;
	vector<Scene*> scene;
	vector<SCoordinate> spawn;
	Type **map;

};



#endif // MAP_H