/**********************************************************************
 * File  : polices.h
 * Author: Lightness1024
 * Date  : 14/02/2006
 *********************************************************************/

#ifndef GPROG_FONTS_HPP
#define GPROG_FONTS_HPP 1

#include <ft2build.h>   // GNU freetype font 2
#include FT_FREETYPE_H
#include "../../../util/windows.h"
#ifdef WINDOWS
  #include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdarg.h>

namespace Engine
{

class GPFont
{
      GLuint listBase;
      GLuint texNames[256];
      int glyph_advances[256];
      char* buf;
      size_t bfsize;
      bool loaded;
      float feedJump;

      void PreparePixMap(int ch, FT_Face face);
      void PrintCmn(const char* fmt, va_list vl);

   public:

      // constructeur annulant le constructeur par defaut:
      GPFont(const char* fontName, int ptSize);

      // la classe est elle bien chargée ?
      bool WereLoadedOk(void);

      // appellez cette fonction pour afficher du texte
      // la chaine de formattage et les arguments iront dans une fonction sprintf
      void Print2D(const char* fmt, ...);

      // appellez cette fonction pour afficher du texte sans modification
      // de la matrice de vue/projection
      void Print3D(const char* fmt, ...);

      // pour connaître la largeur d'un texte:
      // (peut servir pour le centrage)
      int GetStringPixelWidth(char* message);

      // régler la hauteur du saut de ligne !
      inline void SetFeedJump(float feedJ)
      {
         feedJump = feedJ;
      }

      inline float GetFeedJump(void)
      {
         return feedJump;
      }

      // nettoyeur:
      ~GPFont();
};


// fonctions gl necessaires a l'affichage 2d:
void PushScreenCoordinateMatrix(void);
void PopProjectionMatrix(void);

}
#endif
