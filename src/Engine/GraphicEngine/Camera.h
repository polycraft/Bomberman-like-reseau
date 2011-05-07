#ifndef CAMERA_H
#define CAMERA_H

#include "../util/windows.h"
#ifdef WINDOWS
  #include <windows.h>
#endif
#include "ObjectMovable.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

namespace Engine
{
    class Camera : public ObjectMovable
    {
        public:
            Camera();
			//Avec initialisation donné
			Camera(double x, double y, double z, double ciblex, double cibley, double ciblez, double dirx, double diry, double dirz);
            virtual ~Camera();

            /**
            Place la caméra dans l'affichage
            **/
            void draw();

		private:
			double X;
			double Y;
			double Z;
			double cibleX;
			double cibleY;
			double cibleZ;
			double dirX;
			double dirY;
			double dirZ;
    };
}

#endif // CAMERA_H
