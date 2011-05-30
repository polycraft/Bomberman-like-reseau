#ifndef TYPE_H
#define TYPE_H

#include "../Engine/GraphicEngine/Object.h"

enum EType
{
	T_StaticBloc,
	T_BreakableBloc,
	T_Bomberman,
	T_Bomb,
	T_Explosion,
	T_Bonus
};

class Type : public Engine::Object
{

public:
	Type();
	virtual ~Type();
	virtual EType getType()=0;
	virtual void destroyTimeAnim()=0;


};



#endif // TYPE_H
