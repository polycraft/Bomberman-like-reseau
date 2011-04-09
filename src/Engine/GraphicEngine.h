#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include <vector>
#include "Scene.h"
#include "Camera.h"

using namespace std;

namespace Engine
{
    /**
    Moteur de gestion d'affichage
    **/
    class GraphicEngine
    {
        public:
            GraphicEngine();
            virtual ~GraphicEngine();

            /**
            Ajoute une caméra à gérer
            **/
            void addCamera(Camera camera);

            /**
            Ajoute une scene à gérer
            **/
            unsigned int addScene(Scene scene);

            /**
            Ajoute un objet à une scene
            **/
            void addSceneObject(Object object,unsigned idScene=0);
            void addSceneObject(Object object,Scene scene);

            /**
            Met à jour l'affichage
            **/
            void update();
        private:

            /**
            Liste des caméras à gérer
            **/
            vector<Camera> camera;

            /**
            Liste des caméras à gérer
            **/
            vector<Scene> scene;
    };
}
#endif // GRAPHICENGINE_H
