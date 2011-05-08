#include "Model.h"

namespace Engine
{
	Model::Model(string &name, vector<double> point, vector<double> texture, vector<int> indice) : Ressource(name)
	{
		this->construireModel(point,texture,indice);
	}

	Model::~Model()
	{
	}

	void Model::construireModel(vector<double> point, vector<double> texture, vector<int> indice)
	{
		this->nbPoint = point.size();
		this->nbIndice = indice.size();
		this->nbTexture = texture.size();

		//crée les tableaux
		this->point = new GLfloat[this->nbPoint];
		this->indice = new GLuint[this->nbIndice];
		this->texture = new GLfloat[this->nbTexture];

		//puis enregistre
		for(int i = 0;i<this->nbPoint;i++)
		{
			this->point[i] = point[i];
		}
		for(int i = 0;i<this->nbIndice;i++)
		{
			this->indice[i] = indice[i];
		}
		for(int i = 0;i<this->nbTexture;i++)
		{
			this->texture[i] = texture[i];
		}
	}
	
}