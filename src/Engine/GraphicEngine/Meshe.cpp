#include "Meshe.h"

namespace Engine
{
	Meshe::Meshe()
	{

	}

	/*Meshe::Meshe(Texture* texture)
	{
		this->noTexture = texture->getTexture();
	}

	Meshe::Meshe(Ressource* texture)
	{
		 Texture *temp = Ressource::getRessource<Texture>(*texture);
		 this->noTexture = temp->getTexture();
	}*/

	Meshe::~Meshe()
	{

	}

	/*void Meshe::setTexture(Texture* texture)
	{
		this->noTexture = texture->getTexture();
	}
	
		void Meshe::setTexture(Ressource* texture)
	{
		 Texture *temp = Ressource::getRessource<Texture>(*texture);
		 this->noTexture = temp->getTexture();
	}*/

		void Meshe::moveTexture()
		{
			if(cycleTexture < 2) cycleTexture += 1;
			else cycleTexture = 0;

			for(int i = 0;i<this->nbTexture;i++)
			{
				this->texture[i] = this->textureAnim[i+nbTexture*cycleTexture];
			}


		}
}