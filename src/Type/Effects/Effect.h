#ifndef EFFECT_H
#define EFFECT_H

class Bomberman;

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
