#include "LoaderObject.h"

namespace Engine
{
	LoaderObject::LoaderObject()
	{
	}

	LoaderObject::~LoaderObject()
	{
	}

	Ressource* LoaderObject::load(string &name) throw(ExceptionNoFileFound)
	{
		//Pasing de l'objet
		parserObject(name);

		return new Model(name,point,texture,indice);
	}

	void LoaderObject::free(Ressource &ressource) throw(ExceptionBadRessource)
	{
	}

	void LoaderObject::parserObject(string file)
	{
		vector<double> tempTexture;//temporaire pour ensuite trier le tableau des textures
		vector<int> tempNoTexturePoint;
		ifstream fichier(file, ios::in);

		 if(fichier)  // si l'ouverture a réussi
		 {
			 ////ATTENTION IL Y A DES RACCOURCIS, ICI ON TRAITE DES FACES TRIANGULAIRE\\\\

			int a,b,c;
			double infoVertice[3];//les coordonnées des points//face <====RACCOURCI
			double infoVerticeTexture[3];
			double infoTexture[2];

			string infoFace[3];// recupere seulement les faces : f 444/444/444  444/444/444  444/444/444
			


			string ligne;//toute la ligne
			string entete;// prend : v,vt,vn ou f => definie le type

			istringstream iss;


			while( (!fichier.eof()))
			{

				iss.str(ligne);
				iss >> entete;
				if( entete  == "v" )
				{
					iss >> infoVertice[0] >> infoVertice[1] >>infoVertice[2];
					this->point.push_back(infoVertice[0]);
					this->point.push_back(infoVertice[1]);
					this->point.push_back(infoVertice[2]);
				
				}
					else if( entete  == "vt" )
					{
						iss >> infoTexture[0] >> infoTexture[1];
						tempTexture.push_back(infoTexture[0]);
						tempTexture.push_back(infoTexture[1]);
				
					}
						else if( entete  == "f" )
						{
							iss >> infoFace[0] >> infoFace[1] >> infoFace[2];
							iss.clear();
							for(int i=0;i<3;i++)
							{

								iss.str(infoFace[i]);
								sscanf (const_cast<char*>(infoFace[i].c_str()),"%d/%d/%d",&a,&b,&c);
								infoVertice[i]= a;
								infoVerticeTexture[i]= b;
					
							}

							this->indice.push_back(infoVertice[0]-1);
							this->indice.push_back(infoVertice[1]-1);
							this->indice.push_back(infoVertice[2]-1);
							tempNoTexturePoint.push_back(infoVerticeTexture[0]-1);
							tempNoTexturePoint.push_back(infoVerticeTexture[1]-1);
							tempNoTexturePoint.push_back(infoVerticeTexture[2]-1);

						}
			
				iss.clear();


				 getline(fichier,ligne);//on passe a la ligne suivante
			}

			fichier.close();//fermeture du fichier
		 }

		 else
		 {
			 throw new ExceptionNoFileFound();
		 }

		 //trie du tableau des textures
		 for(int i=0; i<tempTexture.size();i++)
		 {
			 this->texture.push_back(tempTexture[2*tempNoTexturePoint[i]]);
			 this->texture.push_back(tempTexture[2*tempNoTexturePoint[i]+1]);

		 }


	}
}