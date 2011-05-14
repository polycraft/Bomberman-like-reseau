#ifndef MAP_H
#define MAP_H

#include "Type/Bomberman.h"
#include "Type/Type.h"
#include <vector>
#include "Engine/GraphicEngine/Scene.h"


using namespace Engine;

enum EGameType{
	Classic,
	CaptureTheFlag
};

typedef struct SCoordinate
{
	int x;
	int y;
} SCoordinate;

class Map : public Ressource
{

public:
	Map(EGameType gameType, int width, int lenght);
	~Map();
	void addBomberman(Bomberman bomberman);
	void addObject(Type* object, int x, int y);
	void addSpawn(int x, int y);
	Scene* getScene(int scene);
	SCoordinate getSpawn(int id);
	int getWidth();
	int getLength();
	Type** operator[] (int index);

private:
	int gameType;
	int width;
	int length;
	vector<Scene*> scene;
	vector<SCoordinate> spawn;
	Type ***map;

};



#endif // MAP_H