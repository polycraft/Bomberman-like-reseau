#ifndef OBJECTMOVABLE_H
#define OBJECTMOVABLE_H

namespace Engine
{
    class ObjectMovable
    {
        public:
            virtual ~ObjectMovable();

            /**
            Réalise une rotation sur l'objet
            **/
            void rotate(double x,double y,double z);

            /**
            Réalise une translation sur l'objet
            **/
            void translation(double x,double y,double z);

            /**
            Enregistre les coordonnées precise de l'objet
            **/
			void setCoordonnes(double x,double y,double z);
            /**
            Enregistre l'angle
            **/
			void setRotation(double x,double y,double z);

        protected:
            ObjectMovable();//Classe abstraite
        protected:

            double transX;
            double rotateX;
            double transY;
            double rotateY;
            double transZ;
            double rotateZ;

    };
}
#endif // OBJECTMOVABLE_H
