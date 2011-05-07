#include "Cube.h"
namespace Engine
{
	Cube::Cube(double height)
	{
		double x,y,z;
		x=y=z=0;
		this->nbIndice = 36;
		this->nbPoint = 24;
		
		//creation des tableaux temporaires
		/*double tempPoint[24] = {
		x-height, y+height, z-height,
		x-height, y-height, z-height,
		x-height, y+height, z+height,
		x-height, y-height, z+height,
		x+height, y+height, z+height,
		x+height, y-height, z+height,
		x+height, y+height, z-height,
		x+height, y-height, z-height
		};

		int tempIndice[36] = {
		0,1,2,2,1,3,
		4,5,6,6,5,7,
		3,1,5,5,1,7,
		0,2,6,6,2,4,
		6,7,0,0,7,1,
		2,3,4,4,3,5
		};

		//crée les tableaux
		this->point = new GLfloat[24];
		this->indice = new GLuint[36];

		//puis enregistre
		for(int i = 0;i<this->nbPoint;i++)
		{
			this->point[i] = tempPoint[i];
		}
		for(int i = 0;i<this->nbIndice;i++)
		{
			this->indice[i] = tempIndice[i];
		}*/

	}


	Cube::~Cube()
	{
	}


}
