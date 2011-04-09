#ifndef OBJECT_H
#define OBJECT_H

#include "ObjectMovable.h"
#include "ObjectData.h"

namespace Engine
{
    class Object : public ObjectMovable
    {
        public:
            Object();
            virtual ~Object();
            /**
            Redimensionne l'objet
            **/
            void scale(double x,double y,double z);

            /**
            Met à jours l'affichage
            **/
            void update();

            /**
            Attache l'objet à des données d'un objet
            **/
            void attach(ObjectData data);
        private:
            double xScale;
            double yScale;
            double zScale;

            ObjectData* data;
    };
}

#endif // OBJECT_H
