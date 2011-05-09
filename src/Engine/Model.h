#ifndef MODEL_H
#define MODEL_H
#include "GraphicEngine/Meshe.h"
#include <vector>


namespace Engine
{
    class Model : public Meshe ,public Ressource
    {
        public:
            Model(string &name, vector<double> point, vector<double> texture, vector<int> indice);
            ~Model();
		private:
			void construireModel(vector<double> point, vector<double> texture, vector<int> indice);
    };
}
#endif // MODEL_H