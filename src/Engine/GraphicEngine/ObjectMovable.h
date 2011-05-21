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
            virtual void translation(double x,double y,double z);

            /**
            Enregistre les coordonnées precise de l'objet
            **/
			virtual void setCoordonnes(double x,double y,double z);
            /**
            Enregistre l'angle
            **/
			void setRotation(double x,double y,double z);

			/**
			Getter coordonnée
			**/
			double getTransX();
			double getTransY();
			double getTransZ();

			/**
			Setter coordonnée
			**/
			void setTransX(double x);
			void setTransY(double y);
			void setTransZ(double z);


			/**
			Getter rotation
			**/
			double getRotateX();
			double getRotateY();
			double getRotateZ();


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
