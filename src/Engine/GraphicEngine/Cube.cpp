#include "Cube.h"
namespace Engine
{
	Cube::Cube(double height,Ressource *noTexture) : Meshe(noTexture)
	{

		this->construireCube(height);
	}

	Cube::Cube(double height,Texture *noTexture) : Meshe(noTexture)
	{

		this->construireCube(height);
	}


	Cube::~Cube()
	{
	}

	void Cube::construireCube(double height)
	{
		double x,y,z;
		x=0;
		y=0;
		z=height/2;

		this->nbPoint = 72;
		this->nbIndice = 36;
		this->nbTexture = 48;



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
		};*/

		/*int tempIndice[36] = {
		0,1,2,2,1,3,
		4,5,6,6,5,7,
		3,1,5,5,1,7,
		0,2,6,6,2,4,
		6,7,0,0,7,1,
		2,3,4,4,3,5
		};*/

		double tempPoint[72] = {
		// face de devant
		-1.0, 1.0, 1.0,            
		-1.0, -1.0, 1.0,          
		1.0, -1.0, 1.0,            
		1.0, 1.0, 1.0,             
 
		// haut
		-1.0, 1.0, -1.0,          
		-1.0, 1.0, 1.0,            
		1.0, 1.0, 1.0,             
		1.0, 1.0, -1.0,

		// arrière
		1.0, 1.0, -1.0,        
		1.0, -1.0, -1.0,          
		-1.0, -1.0, -1.0,          
		-1.0, 1.0, -1.0,           
 
		// dessous
		-1.0, -1.0, 1.0,
		-1.0, -1.0, -1.0,
		1.0, -1.0, -1.0,
		1.0, -1.0, 1.0,
		
		// gauche
		-1.0, 1.0, -1.0,
		-1.0, 1.0, 1.0,
		-1.0, -1.0, 1.0,
		-1.0, -1.0, -1.0,
 
		// droite
		1.0, 1.0, 1.0,
		1.0, 1.0, -1.0,
		1.0, -1.0, -1.0,
		1.0, -1.0, 1.0
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

		/*double tempTexture[] = {
		1.0, 0.0,
		1.0, 1.0,
		0.0, 1.0,
		0.0, 1.0,
		0.0, 0.0,
		1.0, 0.0,
		
		0.0, 0.0,
		1.0, 0.0,
		1.0, 1.0,
		1.0, 1.0,
		0.0, 1.0,
		0.0, 0.0,

		0.0, 0.0,
		1.0, 0.0,
		1.0, 1.0,
		1.0, 1.0,
		0.0, 1.0,
		0.0, 0.0,

		0.0, 0.0,
		1.0, 0.0,
		1.0, 1.0,
		1.0, 1.0,
		0.0, 1.0,
		0.0, 0.0,

		0.0, 0.0,
		1.0, 0.0,
		1.0, 1.0,
		1.0, 1.0,
		0.0, 1.0,
		0.0, 0.0,

		0.0, 0.0,
		1.0, 0.0,
		1.0, 1.0,
		1.0, 1.0,
		0.0, 1.0,
		0.0, 0.0
		};*/

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
