#include "Paquet.h"

namespace Engine
{

Paquet::Paquet(char*data,unsigned int size):data(data),size(size)
{
    //ctor
}

Paquet::~Paquet()
{
    //dtor
}

char * Paquet::getData()
{
    return data;
}

unsigned int Paquet::getSize()
{
    return size;
}

}
