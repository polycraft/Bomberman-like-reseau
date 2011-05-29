#ifndef TEXT_H
#define TEXT_H
#include <string>

#include "GraphicEngine/Text/ManagerFont.h"


namespace Engine
{
typedef enum ETypeText
{
    TT_Text2D,
    TT_Text3D
} ETypeText;

class Text
{
    friend class ManagerFont;
    public:
        Text(ETypeText=TT_Text2D);
        Text(std::string &s,ETypeText);
        Text(std::string &s,ETypeText,double x,double y,double z);
        Text(std::string &s,double x,double y);
        Text(std::string &s,double x,double y,double z);
        virtual ~Text();

        void setCoord(double x,double y,double z);
        void setCoord(double x,double y);

        void setText(const char* s);
        void setText(std::string &s);
        void setType(ETypeText);

        void setColor(double r,double g,double b,double a);

        void setRotate(double x,double y,double z);

        void setScale(double x,double y,double z);

        void setInterLigne(int inter);

        double getX();
        double getY();
        double getZ();
        ETypeText getType();
    protected:
    private:
        double x;
        double y;
        double z;
        ETypeText type;
        std::string text;

        //Couleur
        double r;
        double g;
        double b;
        double a;

        //rotation
        double rotateX;
        double rotateY;
        double rotateZ;

        //scale
        double scaleX;
        double scaleY;
        double scaleZ;

        int interLigne;
};
}
#endif // TEXT_H
