#ifndef CAMERA_H
#define CAMERA_H

#include "ObjectMovable.h"

namespace Engine
{
    class Camera : public ObjectMovable
    {
        public:
            Camera();
            virtual ~Camera();

            /**
            Place la caméra dans l'affichage
            **/
            void update();
    };
}

#endif // CAMERA_H
