#include "ManagerFont.h"

using namespace std;

namespace Engine
{
ManagerFont::ManagerFont(char *s,int size) throw(ExceptionNoFileFound)
{
    font=new GPFont(s, size);

    if (!font->WereLoadedOk())
    {
        throw ExceptionNoFileFound();
    }
}

ManagerFont::ManagerFont(string s,int size) throw(ExceptionNoFileFound)
{
    GPFont* font=new GPFont(s.c_str(), size);

    if (!font->WereLoadedOk())
    {
        throw ExceptionNoFileFound();
    }
}

ManagerFont::~ManagerFont()
{
    delete font;
}

void ManagerFont::addText(Text* text)
{
    this->text.insert(text);
}

void ManagerFont::removeText(Text* text)
{
    this->text.erase(text);
}

void ManagerFont::draw()
{
    set<Text*>::iterator it;
    Text* t;
    for ( it=text.begin() ; it != text.end(); it++ )
    {
		glLoadIdentity();
		//glPushMatrix();
		
        t=*it;
        glColor4ub(t->r, t->g, t->b, t->a);
        glTranslatef(t->x, t->y, t->z);
        glScalef(t->scaleX,t->scaleY,t->scaleZ);
        glRotatef(t->rotateX, 1, 0, 0);
		glRotatef(t->rotateY, 0, 1, 0);
        glRotatef(t->rotateZ, 0, 0, 1);

        if(t->interLigne>-1)
        {
            font->SetFeedJump(t->interLigne);
        }

        switch(t->type)
        {
            case TT_Text2D:
                font->Print2D(t->text.c_str());
            break;
            case TT_Text3D:
                font->Print3D(t->text.c_str());
            break;
        }
		//glPopMatrix();
        
    }
}
}
