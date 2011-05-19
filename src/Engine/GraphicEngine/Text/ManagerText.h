#ifndef MANAGERTEXT_H
#define MANAGERTEXT_H



#include <set>
#include "ManagerFont.h"

namespace Engine
{
class ManagerText
{
    public:
        ManagerText();
        virtual ~ManagerText();

        void addFont(ManagerFont* font);
        void removeFont(ManagerFont* font);

        void draw();
    private:
        std::set<ManagerFont*> fonts;
};
}

#endif // MANAGERTEXT_H
