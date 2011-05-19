#ifndef MANAGERFONT_H
#define MANAGERFONT_H




#include <string>
#include "libText/polices.h"
#include <set>
#include "../../Exception/Exception.h"
namespace Engine
{
class Text;
}
#include "../../Text.h"

namespace Engine
{

class ManagerFont
{
    public:
        ManagerFont(char *s,int size)throw(ExceptionNoFileFound);
        ManagerFont(std::string s,int size)throw(ExceptionNoFileFound);
        virtual ~ManagerFont();

        void addText(Text* text);
        void removeText(Text* text);

        void draw();
    protected:
    private:
        GPFont* font;
        std::set<Text*> text;
};

}

#endif // MANAGERFONT_H
