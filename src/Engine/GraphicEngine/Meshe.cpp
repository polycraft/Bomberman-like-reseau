#include "Meshe.h"

namespace Engine
{
	Meshe::Meshe()
	{

	}

	Meshe::Meshe(Texture* texture)
	{
		this->noTexture = texture->getTexture();
	}

	Meshe::Meshe(Ressource* texture)
	{
		 Texture *temp = Ressource::getRessource<Texture>(*texture);
		 this->noTexture = temp->getTexture();
	}

	Meshe::~Meshe()
	{

	}

	void Meshe::setTexture(Texture* texture)
	{
		this->noTexture = texture->getTexture();
	}
	
		void Meshe::setTexture(Ressource* texture)
	{
		 Texture *temp = Ressource::getRessource<Texture>(*texture);
		 this->noTexture = temp->getTexture();
	}

}