#include "Paquet.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace Engine
{

Paquet::Paquet(char*data,unsigned int size):size(size)
{
    this->data=new char[size];
    memcpy(this->data,data,size);
}

Paquet::Paquet(const Paquet& paquet)
{
    this->data=new char[paquet.size];
    memcpy(this->data,paquet.data,paquet.size);
    size=paquet.size;
}

void Paquet::operator=(const Paquet& paquet)
{
    this->data=new char[paquet.size];
    memcpy(this->data,paquet.data,paquet.size);
    size=paquet.size;
}

Paquet::~Paquet()
{
    delete[] data;
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
