#ifndef OBJECT_H
#define OBJECT_H

#include "../util/windows.h"
#ifdef WINDOWS
  #include <windows.h>
#endif

#include "ObjectMovable.h"
#include "ObjectData.h"
#include "Meshe.h"
#include "../Model.h"
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>

namespace Engine
{
    class Object : public ObjectMovable
    {
        public:
            Object();
            virtual ~Object();
            /**
            Redimensionne l'objet => donne sa taille
            **/
            void setScale(double x,double y,double z);

			/**
            Redimensionne l'objet => bouge sa taille
            **/
			 void scale(double x,double y,double z);

            /**
            Met à jours l'affichage
            **/
            void draw();

            /**
            Attache l'objet à des données d'un objet (meshe)
            **/
            void attach(Meshe* data);
            /**
            Attache l'objet à une ressource ( un model ) / donne sa texture
            **/
			void attach(Ressource* model, Texture* texture);
			void attach(Ressource* model, Ressource* texture);

			//Pour les textures animées:
			void moveTexture();

        private:
            double xScale;
            double yScale;
            double zScale;
			/**
            Visibilité ( visible par defaut )
            **/
			bool visible;

			/**
            Les Datas
            **/
            Meshe* data;
			
    };
}

#endif // OBJECT_H
