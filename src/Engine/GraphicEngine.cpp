#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>

#include "GraphicEngine.h"
#include "Scene.h"
#include "Camera.h"
#include "Object.h"

namespace Engine
{

GraphicEngine::GraphicEngine(string name,unsigned int w, unsigned int h,unsigned int nbCamera,unsigned int nbScene)
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetCaption(name.c_str(),NULL);
    SDL_SetVideoMode(w, h, 32, SDL_OPENGL);

    camera = new vector<Camera*>(nbCamera);
    scene = new vector<Scene*>(nbScene);

    /**
    Ajout d'une scene par defaut
    **/
    scene->push_back(new Scene(TS_Static));
}

GraphicEngine::~GraphicEngine()
{
    //TODO libérer chaque scene et caméra
    delete camera;
    delete scene;
    SDL_Quit();
}

unsigned int GraphicEngine::addCamera(Camera *camera)
{
    this->camera->push_back(camera);

    //Retourne l'id de la nouvelle camera
    return this->camera->size()-1;
}

unsigned int GraphicEngine::addScene(Scene *scene)
{
    this->scene->push_back(scene);

    //Retourne l'id de la nouvelle scene
    return this->scene->size()-1;
}

void GraphicEngine::addSceneObject(Object *object,unsigned idScene)
{
    (*scene)[idScene]->addObject(object);
}

void GraphicEngine::addSceneObject(Object *object,Scene *scene)
{
    scene->addObject(object);
}

void GraphicEngine::update(Camera *camera)
{
    //Mise à jours de la caméra
    camera->update();

    //Mise à jours des scenes
    vector<Scene*>::iterator it;

    for ( it=scene->begin() ; it < scene->end(); it++ )
    {
        (*it)->update();
    }
}

void GraphicEngine::update(unsigned int idCamera)
{
    this->update((*camera)[idCamera]);
}

}//namespace Engine
