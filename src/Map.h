#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Type.h"

enum EGameType{
	StaticBloc,
	BreakableBloc
};

class Map
{

public:
	Map(EGametype gameType, int width, int lenght);
	~Map();
	void addBOmberman(Bomberman bomberman);
	void addObject(Type type, int x, int y);
	void addSpawn(int id);
	Scene getScene(int scene);
	coordinate getSpawn(int id);
	int getWidth();
	int getLength();
	Type operator[] (int index);

private:
	int gameType;
	int width;
	int length;
	vector<coordinate> spawn;
	Type map[][];

};



#endif // MAP_H