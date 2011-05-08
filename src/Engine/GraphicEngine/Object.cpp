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

		//La couleur Ambiante de l'objet est mise au BLANC ( sinon vert par defaut)
		glColor3ub(255,255,255);

		//Texture a appliquer
		glBindTexture(GL_TEXTURE_2D,this->data->noTexture);

		//Prepare la pose de la texture
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		//on prepare le traçage des points
		glEnableClientState( GL_VERTEX_ARRAY );

		//donne le tableau des textures
		glTexCoordPointer(2, GL_FLOAT, 0, this->data->texture);
		//donne le tableau des points
		glVertexPointer( 3, GL_FLOAT, 0, this->data->point );

		glDrawElements( GL_TRIANGLES, this->data->nbIndice , GL_UNSIGNED_INT, data->indice );
		//on arrete le traçage
		glDisableClientState( GL_VERTEX_ARRAY );
		//on arrete le traçage de texture
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		glPopMatrix();
    }

	void Object::attach(Meshe* data)
	{
		this->data = data;
	}
}
