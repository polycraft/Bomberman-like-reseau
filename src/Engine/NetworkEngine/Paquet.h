#ifndef PAQUET_H
#define PAQUET_H

namespace Engine
{
class Paquet
{
    public:
        Paquet(char*data,unsigned int size);
        Paquet(const Paquet& paquet);
        void operator=(const Paquet& paquet);
        virtual ~Paquet();
        template<class T>
        T getData()
        {
            return reinterpret_cast<T>(data);
        }
        char * getData();
        unsigned int getSize();
    protected:
    private:
    char* data;
    unsigned int size;
};
}

#endif // PAQUET_H
