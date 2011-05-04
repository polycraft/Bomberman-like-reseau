#ifndef OBJECTDATA_H
#define OBJECTDATA_H

namespace Engine
{
    class ObjectData
    {
        public:
            ObjectData();
            virtual ~ObjectData();
        protected:
        private:
            double* point;
            double* indice;
            double* texture;
    };
}
#endif // OBJECTDATA_H
