#include "ManagerText.h"
using namespace std;
namespace Engine
{
ManagerText::ManagerText()
{
    //ctor
}

ManagerText::~ManagerText()
{
    //dtor
}

void ManagerText::addFont(ManagerFont* font)
{
    fonts.insert(font);
}
void ManagerText::removeFont(ManagerFont* font)
{
    fonts.erase(font);
}

void ManagerText::draw()
{
    set<ManagerFont*>::iterator it;

    for ( it=fonts.begin() ; it != fonts.end(); it++ )
    {
        (*it)->draw();
    }
}
}
