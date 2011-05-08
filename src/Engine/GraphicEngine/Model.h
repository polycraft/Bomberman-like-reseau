#ifndef MODEL_H
#define MODEL_H
#include "Meshe.h"
#include <vector>

namespace Engine
{
    class Model : public Meshe
    {
        public:
            Model(vector<double> point, vector<double> texture, vector<int> indice, Ressource *noTexture);
			Model(vector<double> point, vector<double> texture, vector<int> indice, Texture *noTexture);
            ~Model();
		private:
			void construireModel(vector<double> point, vector<double> texture, vector<int> indice);
    };
}
#endif // MODEL_H