#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Object.h"
#include "ObjectMovable.h"

using namespace std;

namespace Engine
{
    typedef enum
    {
        TS_Static,
        TS_Dynamique
    } typeScene;

    class Scene : public ObjectMovable
    {
        public:
            Scene(typeScene type,unsigned int nbObject=50);

            virtual ~Scene();

            /**
            Met à jours l'affichage
            **/
            void draw();

            /**
            Ajoute un objet
            **/
            void addObject(Object *object);
        private:

            /**
            Liste des objets à gérer
            **/
            vector<Object*> object;

            /**
            Type de scène
            **/
            typeScene type;

			            /**
            Visibilité ( visible par defaut )
            **/
			bool visible;



    };
}
#endif // SCENE_H
