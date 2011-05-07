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
        vector<Object*>::iterator it;
       for ( it=object.begin() ; it < object.end(); it++ )
        {
			(*it)->draw();
        }
    }

    void Scene::addObject(Object *object)
    {
        this->object.push_back(object);
    }
}
