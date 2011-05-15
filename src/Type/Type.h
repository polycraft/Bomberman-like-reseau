#ifndef TYPE_H
#define TYPE_H

#include "../Engine/GraphicEngine/Object.h"
#include "../Engine/ManagerRessource.h"
#include "../Engine/Ressource.h"
#include "../Engine/GraphicEngine/Cube.h"

using namespace Engine;

enum EType
{
	T_StaticBloc,
	T_BreakableBloc,
	T_Bomberman,
	T_Bomb,
	T_Explosion,
	T_Bonus
};

class Type : public Object
{

public:
	Type();
	virtual ~Type();
	virtual EType getType()=0;

};



#endif // TYPE_H
