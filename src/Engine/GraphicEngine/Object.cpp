#include "Object.h"

namespace Engine
{
    Object::Object()
    {
        //ctor
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
		//on prepare le traçage des triangles
		glEnableClientState( GL_VERTEX_ARRAY );

		glVertexPointer( 3, GL_FLOAT, 0, data->point );


		glDrawElements( GL_TRIANGLES, data->nbIndice , GL_UNSIGNED_INT, data->indice );

		glDisableClientState( GL_VERTEX_ARRAY );
    }

	void Object::attach(Meshe* data)
	{
		this->data = data;
	}
}
