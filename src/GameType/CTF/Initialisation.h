#ifndef INITIALISATION_H
#define INITIALISATION_H

#include "../Phase.h"


class Initialisation : public Phase
{

public:
	Initialisation(CollisionDetector *collision);
	virtual ~Initialisation();
	void init();
	void run();

private:

};



#endif // INITIALISATION_H
