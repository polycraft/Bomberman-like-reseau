#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include "../util/windows.h"
#ifdef WINDOWS
  #include <windows.h>
#endif

#include <vector>
#include <iostream>
#include <string>
#include "Scene.h"
#include "Camera.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>

#include "Text/ManagerText.h"
#include "Text/ManagerFont.h"

using namespace std;

namespace Engine
{
    /**
    Moteur de gestion d'affichage
    **/
    class GraphicEngine
    {
        public:
            GraphicEngine(string name,unsigned int w, unsigned int h,unsigned int nbCamera=1,unsigned int nbScene=1);
            virtual ~GraphicEngine();

            /**
            Ajoute une caméra à gérer
            **/
            unsigned int addCamera(Camera *camera);

            /**
            Ajoute une scene à gérer
            **/
            unsigned int addScene(Scene *scene);

            /**
            Ajoute un objet à une scene
            **/
            void addSceneObject(Object *object,unsigned idScene=0);
            void addSceneObject(Object *object,Scene *scene);

            ManagerText& getManagerText();

            /**
            Met à jour l'affichage
            **/
            void draw(Camera *camera);
            void draw(unsigned int idCamera=0);
        private:
            /**
            Liste des caméras à gérer
            **/
            vector<Camera*> camera;

            /**
            Liste des caméras à gérer
            **/
            vector<Scene*> scene;

            ManagerText text;
    };
}
#endif // GRAPHICENGINE_H
