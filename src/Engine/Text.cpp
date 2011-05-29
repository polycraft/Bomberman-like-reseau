#include "Text.h"

using namespace std;

namespace Engine
{
Text::Text(ETypeText type):type(type)
{
    interLigne=-1;
    scaleX=1;
    scaleY=1;
    scaleZ=1;
}

Text::Text(string &s,ETypeText type):text(s),type(type)
{
    interLigne=-1;
        scaleX=1;
    scaleY=1;
    scaleZ=1;
}

Text::Text(string &s,ETypeText type,double x,double y,double z):text(s),type(type),x(x),y(y),z(z)
{
    interLigne=-1;
        scaleX=1;
    scaleY=1;
    scaleZ=1;
}

Text::Text(string &s,double x,double y):text(s),x(x),y(y),z(0)
{
    type=TT_Text2D;
    interLigne=-1;
        scaleX=1;
    scaleY=1;
    scaleZ=1;
}

Text::Text(string &s,double x,double y,double z):text(s),x(x),y(y),z(z)
{
    type=TT_Text3D;
    interLigne=-1;
        scaleX=1;
    scaleY=1;
    scaleZ=1;
}

Text::~Text()
{

}

void Text::setCoord(double x,double y,double z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}
void Text::setCoord(double x,double y)
{
    this->x=x;
    this->y=y;
}

void Text::setText(const char* s)
{
    text=s;
}

void Text::setText(string &s)
{
    text=s;
}

void Text::setType(ETypeText type)
{
    this->type=type;
}

void Text::setColor(double r,double g,double b,double a)
{
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
}

void Text::setRotate(double x,double y,double z)
{
    rotateX=x;
    rotateY=y;
    rotateZ=z;
}

void Text::setScale(double x,double y,double z)
{
    scaleX=x;
    scaleY=y;
    scaleZ=z;
}

void Text::setInterLigne(int inter)
{
    interLigne=inter;
}

double Text::getX()
{
    return x;
}

double Text::getY()
{
    return y;
}

double Text::getZ()
{
    return z;
}

ETypeText Text::getType()
{
    return type;
}
}
