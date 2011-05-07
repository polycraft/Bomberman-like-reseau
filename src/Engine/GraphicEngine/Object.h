#ifndef OBJECT_H
#define OBJECT_H

#include "../util/windows.h"
#ifdef WINDOWS
  #include <windows.h>
#endif

#include "ObjectMovable.h"
#include "ObjectData.h"
#include "Meshe.h"

#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>

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
            void draw();

            /**
            Attache l'objet à des données d'un objet
            **/
            void attach(Meshe* data);

        private:
            double xScale;
            double yScale;
            double zScale;

            Meshe* data;
    };
}

#endif // OBJECT_H
