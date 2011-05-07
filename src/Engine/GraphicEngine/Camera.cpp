#include "Camera.h"

namespace Engine
{
    Camera::Camera()
    {
		//Par defaut : camera en (0,0,0) regarde vers (1,0,0) verticalement (0,0,1)
		//Position de depart de la camera par defaut;
        X=0;
		Y=0;
		Z=0;
		//cible par defaut
		cibleX=1;
		cibleY=0;
		cibleZ=0;
		//direction de la verticale de la vue Camera
		dirX=0;
		dirY=0;
		dirZ=1;
		
		//ObjectMOvable Init
		transX=transY=transZ=0;
		rotateX=rotateY=rotateZ=0;

    }

	Camera::Camera(double x, double y, double z, double ciblex, double cibley, double ciblez, double dirx, double diry, double dirz)
	{
		//Position de depart de la camera
        X= x;
		Y= y;
		Z= z;
		//cible par defaut
		cibleX=ciblex;
		cibleY=cibley;
		cibleZ=ciblez;
		//direction de la verticale de la vue Camera
		dirX=dirx;
		dirY=diry;
		dirZ=dirz;
		
		//ObjectMOvable Init
		transX=transY=transZ=0;
		rotateX=rotateY=rotateZ=0;
	}

    Camera::~Camera()
    {
        //dtor
    }

    void Camera::draw()
    {
		//affichage camera

		gluLookAt(X,Y,Z,cibleX,cibleY,cibleZ,dirX,dirY,dirZ);

		//modification de la matrice
		/*glTranslated(transX,transY,transZ);
		glRotated(rotateX,1,0,0);
		glRotated(rotateY,0,1,0);
		glRotated(rotateZ,0,0,1);*/

    }
}
