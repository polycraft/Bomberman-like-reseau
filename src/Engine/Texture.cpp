#include "Texture.h"

namespace Engine
{
	Texture::Texture(std::string &name,GLuint texture):Ressource(name)
	{
		this->texture = texture;
	}

	Texture::~Texture()
	{
		//dtor
	}

	GLuint Texture::getTexture()
	{
		return this->texture;
	}
	

}