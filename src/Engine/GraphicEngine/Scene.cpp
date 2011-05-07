#include <vector>

#include "Scene.h"
#include "Object.h"

namespace Engine
{
    Scene::Scene(typeScene type,unsigned int nbObject)
    {

        this->type=type;
		this->visible = true;
        //object=vector<Object*>;
    }

    Scene::~Scene()
    {
        //todo Libérer chaque objet
    }

    void Scene::draw()
    {
		//Translation / rotations de la scene
		glPushMatrix();
		glTranslated(transX,transY,transZ);
		glRotated(rotateX,1,0,0);
		glRotated(rotateY,0,1,0);
		glRotated(rotateZ,0,0,1);

		//Construction des objets de la scene
        vector<Object*>::iterator it;
       for ( it=object.begin() ; it < object.end(); it++ )
        {
			(*it)->draw();
        }

	   glPopMatrix();
    }

    void Scene::addObject(Object *object)
    {
        this->object.push_back(object);
    }
}
