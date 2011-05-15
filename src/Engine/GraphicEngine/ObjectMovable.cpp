#include "ObjectMovable.h"

namespace Engine
{
    ObjectMovable::ObjectMovable()
    {
		transX=transY=transZ=rotateX=rotateY=rotateZ=0;
		//ctor
    }

    ObjectMovable::~ObjectMovable()
    {
        //dtor
    }

    void ObjectMovable::rotate(double x,double y,double z)
    {
		rotateX += x;
		rotateY += y;
		rotateZ += z;
    }

    void ObjectMovable::translation(double x,double y,double z)
    {
		transX += x;
		transY += y;
		transZ += z;
    }

	void ObjectMovable::setRotation(double x,double y,double z)
	{
		rotateX = x;
		rotateY = y;
		rotateZ = z;
	}

    void ObjectMovable::setCoordonnes(double x,double y,double z)
	{
		transX = x;
		transY = y;
		transZ = z;
	}

	double ObjectMovable::getTransX()
	{
	    return transX;
	}

    double ObjectMovable::getTransY()
	{
	    return transY;
	}

    double ObjectMovable::getTransZ()
	{
	    return transZ;
	}

    double ObjectMovable::getRotateX()
    {
        return rotateX;
    }

    double ObjectMovable::getRotateY()
    {
        return rotateX;
    }

    double ObjectMovable::getRotateZ()
    {
        return rotateX;
    }
}
