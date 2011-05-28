#include "Object.h"

namespace Engine
{
    Object::Object()
    {
		xScale = 1;
		yScale = 1;
		zScale = 1;
        this->visible = true;
        this->alive=true;
		this->alphaColor=255;
    }

    Object::~Object()
    {
        //dtor
    }

    void Object::setScale(double x,double y,double z)
    {
		    xScale = x;
            yScale = y;
            zScale = y;
    }

    void Object::scale(double x,double y,double z)
    {
		xScale += x;
        yScale += y;
        zScale += z;
    }

	double Object::getXScale()
	{
		return this->xScale;
	}

	double Object::getYScale()
	{
		return this->yScale;
	}

	double Object::getZScale()
	{
		return this->zScale;
	}




    bool Object::draw()
    {
        if(!alive)
        {
            return false;
        }
        if(!visible)
        {
            return true;
        }

		if( this->alphaColor < 255)
		{
			glEnable (GL_BLEND);
			glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}


				


		//Nouveau Repere
		glPushMatrix();
		//scaling / Translation / rotations de l'objet



		glTranslated(transX,transY,transZ);
		glRotated(rotateX,1,0,0);
		glRotated(rotateY,0,1,0);
		glRotated(rotateZ,0,0,1);
		glScalef( xScale, yScale, zScale );

		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.0f);

		//La couleur Ambiante de l'objet est mise au BLANC ( sinon vert par defaut)
		glColor4ub(255,255,255,this->alphaColor);


		//Texture a appliquer
		glBindTexture(GL_TEXTURE_2D,this->noTexture);

		//donne le tableau des points
		glVertexPointer( 3, GL_FLOAT, 0, this->data->point );

		//on prepare le traçage des points
		glEnableClientState( GL_VERTEX_ARRAY );

		//donne le tableau des textures
		glTexCoordPointer(2, GL_FLOAT, 0, this->data->texture);
		//Prepare la pose de la texture
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		


		glDrawElements( GL_TRIANGLES, this->data->nbIndice , GL_UNSIGNED_INT, data->indice );
		//on arrete le traçage
		glDisableClientState( GL_VERTEX_ARRAY );
		//on arrete le traçage de texture
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		glDisable(GL_ALPHA_TEST);
		//Nouveau Repere detruit
		glPopMatrix();

		return true;
    }

	void Object::attach(Meshe* data)
	{
		this->data = data;
	}

	void Object::attach(Ressource* model, Texture* texture)
	{
		Meshe *temp = Ressource::getRessource<Model>(*model);
		this->data = temp;
		this->setTexture(texture);
	}

	void Object::attach(Ressource* model, Ressource* texture)
	{
		Meshe *temp = Ressource::getRessource<Model>(*model);
		this->data = temp;
		this->setTexture(texture);
	}

	void Object::moveTexture()
	{
		this->data->moveTexture();
	}

	void Object::destroy()
	{
	    this->alive=false;
	}

	void Object::setTexture(Texture* texture)
	{
		this->noTexture= texture->getTexture();
	}

	void Object::setTexture(Ressource* texture)
	{
		Texture *temp = Ressource::getRessource<Texture>(*texture);
		this->noTexture = temp->getTexture();
	}
	
	void Object::setAlpha(int alpha)
	{
		this->alphaColor = alpha;
	}

	void Object::setVisible(bool visible)
	{
	    this->visible=visible;
	}

	bool Object::getVisible()
	{
	    return visible;
	}
}
