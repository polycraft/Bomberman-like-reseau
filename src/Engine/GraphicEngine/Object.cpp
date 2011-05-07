#include "Object.h"

namespace Engine
{
    Object::Object()
    {
        this->visible = true;
    }

    Object::~Object()
    {
        //dtor
    }

    void Object::scale(double x,double y,double z)
    {

    }

    void Object::draw()
    {
		//Translation / rotations de l'objet
		glPushMatrix();
		glTranslated(transX,transY,transZ);
		glRotated(rotateX,1,0,0);
		glRotated(rotateY,0,1,0);
		glRotated(rotateZ,0,0,1);

		//on prepare le traçage des triangles

		glEnableClientState( GL_VERTEX_ARRAY );

		glVertexPointer( 3, GL_FLOAT, 0, this->data->point );


		glDrawElements( GL_TRIANGLES, this->data->nbIndice , GL_UNSIGNED_INT, data->indice );

		glDisableClientState( GL_VERTEX_ARRAY );

		glPopMatrix();
    }

	void Object::attach(Meshe* data)
	{
		this->data = data;
	}
}
