#include "CollisionDetector.h"

CollisionDetector::CollisionDetector(Map* map):map(map)
{

}

CollisionDetector::~CollisionDetector()
{

}

ECollision CollisionDetector::detect(EType type,int x,int y)
{
    if(type==T_Bomberman)
    {
        switch(map->get(x,y)->getType())
        {
            case T_Bomb:
            case T_BreakableBloc:
            case T_StaticBloc:
                return C_Block;
            case T_Explosion:
                return C_Kill;
            case T_Bonus:
                return C_Bonus;
            default:
                return C_Nothing;
        }
    }
    else if(type==T_Explosion)
    {
        switch(map->get(x,y)->getType())
        {
            case T_Bomb:
                return C_Explose;
            case T_BreakableBloc:
            case T_StaticBloc:
            case T_Explosion:
                return C_Block;
            case T_Bonus:
                return C_Kill;
            default:
                return C_Nothing;
        }
    }
    return C_Nothing;
}
