#include "Meshe.h"

namespace Engine
{
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
	

}