#ifndef MAP_H
#define MAP_H

#include "Type/Bomberman.h"
#include "Type/Type.h"
#include <vector>
#include "Engine/GraphicEngine/Scene.h"
#include "Engine/MainEngine.h"
#include "Engine/Ressource.h"
#include "Engine/ManagerRessource.h"
#include "Type/StaticBloc.h"
#include "Type/BreakableBloc.h"

using namespace Engine;

enum EScene{
	T_World=0,
	T_Map=1,
	T_Dyn=2
};

enum EGameType{
	T_Classic,
	T_CaptureTheFlag
};

typedef struct SCoordinate
{
	int x;
	int y;
} SCoordinate;

class Map : public Ressource
{

public:
	Map(string &name, EGameType gameType, int width, int lenght);
	~Map();
	void addBomberman(Bomberman *bomberman,SCoordinate coord);
	void addObject(Type* object, int x, int y, EScene scene);
	void addSpawn(int x, int y);
	Scene* getScene(EScene scene);
	SCoordinate getSpawn(int id);
	int getWidth();
	int getHeight();
	Type* get(int x,int y);
	void set(Type* object,int x,int y);
	void setEngine(MainEngine* engine);
	void buildScenes();

private:
	int gameType;
	int width;
	int height;
	vector<Scene*> scene;
	vector<SCoordinate> spawn;
	Type ***map;
	MainEngine* engine;

};



#endif // MAP_H
