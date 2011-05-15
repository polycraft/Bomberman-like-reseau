#include "Cube.h"
namespace Engine
{
	Cube::Cube(double height)
	{

		this->construireCube(height);
	}



	Cube::~Cube()
	{
	}

	void Cube::construireCube(double height)
	{
		this->hasTransparentTexture = false;
		double x,y,z;
		x=0;
		y=0;
		z=height/2;

		this->nbPoint = 72;
		this->nbIndice = 36;
		this->nbTexture = 48;

		double tempPoint[72] = {
		// face de devant
		-5.0, 5.0, 5.0,            
		-5.0, -5.0, 5.0,          
		5.0, -5.0, 5.0,            
		5.0, 5.0, 5.0,             
 
		// haut
		-5.0, 5.0, -5.0,          
		-5.0, 5.0, 5.0,            
		5.0, 5.0, 5.0,             
		5.0, 5.0, -5.0,

		// arrière
		5.0, 5.0, -5.0,        
		5.0, -5.0, -5.0,          
		-5.0, -5.0, -5.0,          
		-5.0, 5.0, -5.0,           
 
		// dessous
		-5.0, -5.0, 5.0,
		-5.0, -5.0, -5.0,
		5.0, -5.0, -5.0,
		5.0, -5.0, 5.0,
		
		// gauche
		-5.0, 5.0, -5.0,
		-5.0, 5.0, 5.0,
		-5.0, -5.0, 5.0,
		-5.0, -5.0, -5.0,
 
		// droite
		5.0, 5.0, 5.0,
		5.0, 5.0, -5.0,
		5.0, -5.0, -5.0,
		5.0, -5.0, 5.0
		};


		int tempIndice[36] = {
		1,0,2,3,0,2,
		4,5,7,6,5,7,
		8,9,11,10,9,11,
		12,13,15,14,13,15,
		16,17,19,18,17,19,
		20,21,23,22,21,23
		};

		double tempTexture[48] = {
		// devant
		0, 1,    
		0, 0,    
		1, 0,     
		1, 1,    
 
		// dessus
		0, 1,   
		0, 0,     
		1, 0,    
		1, 1,

		// derrière
		0, 1,    
		0, 0,     
		1, 0,    
		1, 1,    
 
		// dessous
		0, 1,   
		0, 0,     
		1, 0,    
		1, 1,

		// gauche
		0, 1,  
		0, 0,     
		1, 0,      
		1, 1,      
 
		// droite
		0, 1,     
		0, 0,      
		1, 0,      
		1, 1
		};

		//crée les tableaux
		this->point = new GLfloat[72];
		this->indice = new GLuint[36];
		this->texture = new GLfloat[48];

		//puis enregistre
		for(int i = 0;i<this->nbPoint;i++)
		{
			this->point[i] = tempPoint[i];
		}
		for(int i = 0;i<this->nbIndice;i++)
		{
			this->indice[i] = tempIndice[i];
		}
		for(int i = 0;i<this->nbTexture;i++)
		{
			this->texture[i] = tempTexture[i];
		}
	}

}
