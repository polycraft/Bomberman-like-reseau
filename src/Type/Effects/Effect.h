#ifndef EFFECT_H
#define EFFECT_H
class Effect;

#include "../Bomberman.h"

class Effect
{
	public:
		Effect();
		virtual ~Effect();
		virtual void enableEffect(Bomberman *bomberman)=0;


	protected:
		Bomberman *bomberman;
};

#else


#endif // EFFECT_H