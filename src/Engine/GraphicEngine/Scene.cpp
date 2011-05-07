#include <vector>

#include "Scene.h"
#include "Object.h"

namespace Engine
{
    Scene::Scene(typeScene type,unsigned int nbObject)
    {
        this->type=type;
        object= new vector<Object*>(nbObject);
    }

    Scene::~Scene()
    {
        //todo Libérer chaque objet
        delete object;
    }

    void Scene::draw()
    {
        vector<Object*>::iterator it;

        for ( it=object->begin() ; it < object->end(); it++ )
        {
			(*it)->draw();
        }
    }

    void Scene::addObject(Object *object)
    {
        this->object->push_back(object);
    }
}
