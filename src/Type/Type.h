#ifndef TYPE_H
#define TYPE_H

#include "../Engine/GraphicEngine/Object.h"
#include "../Engine/ManagerRessource.h"
#include "../Engine/Ressource.h"

using namespace Engine;

enum EType
{
	T_StaticBLoc,
	T_BreakableBloc,
	T_Bomberman,
	T_Bomb,
	T_Explosion
};

class Type : public Object
{

public:
	Type();
	virtual ~Type();
	virtual EType getType()=0;

};



#endif // TYPE_H