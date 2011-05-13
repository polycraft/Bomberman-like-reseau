#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include <map>

namespace Engine
{
    typedef enum ECollision
    {
        C_Kill,
        C_Explose,
        C_Block,
        C_Bonus,
        C_Nothing
    } EColision;

    class CollisionDetector
    {
        public:
            /**
            Constructeur
            **/
            CollisionDetector(Map* map);
            virtual ~CollisionDetector();

            /**
            Detecte l'incompatibilité sur une case
            **/
            ECollision detect(EType type,int x,int y);
        private:
        Map *map;
    };
}

#endif // COLLISIONDETECTOR_H
