#include "Fire.h"

namespace Engine
{
	Fire::Fire()
	{

		this->buildFire();
		this->cycleTexture = 0;
	}

	Fire::~Fire()
	{
	}

	void Fire::buildFire()
	{
		//ENregistrament de l'animation de la texture *3
		this->tailleTextureAnim = 48;
		double tempTotalTextureAnim[48] = {
		// devant1
		0.333, 0,    
		0, 0,    
		0, 1,     
		0.333, 1,    
 
		// dessus1
		0.333, 0,    
		0, 0,    
		0, 1,     
		0.333, 1, 

		// devant2
		0.666, 0,    
		0.333, 0,    
		0.333, 1,     
		0.666, 1,    
 
		// dessus2
		0.666, 0,    
		0.333, 0,    
		0.333, 1,     
		0.666, 1,

		// devant3
		1, 0,    
		0.666, 0,    
		0.666, 1,     
		1, 1,    
 
		// dessus3
		1, 0,    
		0.666, 0,    
		0.666, 1,     
		1, 1
		};

		this->hasTransparentTexture=true;

		this->nbPoint = 24;
		this->nbIndice = 12;
		this->nbTexture = 16;
		

		double tempPoint[24] = {
		// face de devant
		0, 5, -2.5,            
		0, 5, 2.5,          
		0, -5, 2.5,            
		0, -5, -2.5,             
 
		// haut
		2.5, 5, 0,          
		-2.5, 5, 0,            
		-2.5, -5, 0,             
		2.5, -5, 0
		};


		int tempIndice[12] = {
		1,0,2,3,0,2,
		4,5,7,6,5,7
		};

		//crée les tableaux
		this->point = new GLfloat[24];
		this->indice = new GLuint[12];
		this->texture = new GLfloat[16];
		this->textureAnim = new double[48];

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
			this->texture[i] = tempTotalTextureAnim[i];
		}
		for(int i = 0;i<this->tailleTextureAnim;i++)
		{
			this->textureAnim[i] = tempTotalTextureAnim[i];
		}
	}


}