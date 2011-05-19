/**********************************************************************
 * File  : polices.c
 * Author: Lightness1024
 * Date  : 14/02/2006
 *
 *             basé sur la 'lesson 43' des tutoriels de nehe
 *
 *********************************************************************/


#include "polices.h"

namespace Engine
{

static int NextPow2(int a)  // retourne puissance de deux directement supérieure à a.
{
   int rval = 1;
   while (rval < a)
      rval <<= 1;
   return rval;
}

// initialisation / chargement
GPFont::GPFont(const char* fontName, int ptSize)
{
   FT_Library ftlib;
   FT_Face face;
   loaded = false;

   if (FT_Init_FreeType(&ftlib))
      return;
   if (FT_New_Face(ftlib, fontName, 0, &face))
      return;

   bfsize = 1;
   buf = new char[1];

   FT_Set_Char_Size(face, 0, ptSize << 6, 96, 96); // résolution courante des écrans: 96 dpi

   listBase = glGenLists(256);  // on réserve des display lists opengl
   glGenTextures(256, texNames);  // autant de textures
   for (int ch = 0; ch < 256; ++ch)
      PreparePixMap(ch, face);    // pour chaque char son sprite

   FT_Done_Face(face);
   FT_Done_FreeType(ftlib);

   feedJump = ptSize + 5;
   loaded = true;
}

// on peut vérifier que le constructeur a bien fait son travail
bool GPFont::WereLoadedOk(void)
{
   return loaded;
}

void GPFont::PreparePixMap(int ch, FT_Face face)
{
   // on fait la conversion du caractère en indice de glyphe
   // puis en bitmap antialiasé en une commande:
   FT_Load_Char(face, ch, FT_LOAD_RENDER);
   FT_Bitmap* pgpix = &face->glyph->bitmap;  // raccourci
   int w, h;
   w = NextPow2(pgpix->width);   // on fait une texture alignée
   h = NextPow2(pgpix->rows);
   // on alloue le pixmap (bitmap monochrome-alpha)
   GLubyte* pixmap = new GLubyte[w * h * 2];
   // il faut remplir cet espace et copier la glyphe.
   // attention au padding
   int x, y;
   for (x = 0; x < w; ++x)
   {
      for (y = 0; y < h; ++y)
      {
         if (x < pgpix->width && y < pgpix->rows)
            pixmap[2 * (y * w + x)] = pixmap[2 * (y * w + x) + 1] = pgpix->buffer[y * pgpix->width + x];
         else
            pixmap[2 * (y * w + x)] = pixmap[2 * (y * w + x) + 1] = 0;  // chrome noir et alpha 100%
      }
   }
   glBindTexture(GL_TEXTURE_2D, texNames[ch]);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);  // pas pigé pkoi ca devait être là ca
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, pixmap);

   glNewList(listBase + ch, GL_COMPILE);
   {
      // activer la bonne texture:
      glBindTexture(GL_TEXTURE_2D, texNames[ch]);
      glPushMatrix();
      // déplacer un peu a droite (voir la métrique des glyphes):
      glTranslatef(face->glyph->bitmap_left, 0, 0);
      // déplacer en bas en cas de glyphe dépassant la base-line:
      glTranslatef(0, face->glyph->bitmap_top - pgpix->rows, 0);

      // trouver les coordonnées de texture où s'arreter
      // c'est un contre effet du padding:
      float	u, v;
      u = (float)pgpix->width / w;
      v = (float)pgpix->rows / h;

      // on dessine le sprite:

      glBegin(GL_QUADS);
      {
         glTexCoord2d(0, 0); glVertex3f(0, pgpix->rows, 0);
         glTexCoord2d(0, v); glVertex3f(0, 0, 0);
         glTexCoord2d(u, v); glVertex3f(pgpix->width, 0, 0);
         glTexCoord2d(u, 0); glVertex3f(pgpix->width, pgpix->rows, 0);
      }
      glEnd();
      glPopMatrix();
      // on stocke les avances pour faire la fonction qui donne la largeur d'une chaine
      glyph_advances[ch] = face->glyph->advance.x >> 6;
      // on avance le 'stylo' de ce qu'il faut dans la métrique:
      glTranslatef(face->glyph->advance.x >> 6, 0, 0);
   }
   glEndList();

   delete [] pixmap;
}

// récupère la largeur en pixel que prendra l'affichage d'une chaine
int GPFont::GetStringPixelWidth(char* message)
{
   if (!loaded)
      return -1;

   int i;
   int sum = 0;
   int len = strlen(message);
   for (i = 0; i < len; ++i)
   {
      sum += glyph_advances[(int)((unsigned char)message[i])];
   }
   return sum;
}

// affiche dans l'espace
void GPFont::PrintCmn(const char* fmt, va_list vl)
{
   if (!loaded)
      return;

   glPushAttrib(GL_ALL_ATTRIB_BITS);

   glEnable(GL_TEXTURE_2D);
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

   int len = strlen(fmt);
   if ((signed)bfsize <= len)
   {
      delete [] buf;
      buf = new char[len + 10];
      bfsize = len + 10;
   }

   int n = 0;
   do
   {
      n = vsnprintf(buf, bfsize, fmt, vl);
      if (n < 0 || n >= (signed)bfsize)  // pas assez d'espace dans la chaine
      {
         if (n < 0)  // glib <= 2.0 : voir le man de vsnprintf
         {
            len += 30;  // on ne sait pas de combien faut augmenter
            delete [] buf;
            buf = new char[len];
            bfsize = len;
         }
         else
         {
            char* tmp = new char[n + 1];   // redimensionnement pile poil
            memcpy(tmp, buf, n + 1);
            delete [] buf;
            buf = tmp;
         }
         n = -1; // pour le while
      }
      else
         len = n;  // ca s'est bien passé
   } while (n < 0);

   // deuxième étape, afficher ligne par ligne.
   // on va remplacer tous les \n par des \0
   // et compter les écarts
   int nbLines = 1;
   int c;
   for (c = 0; c < len; ++c)
      if (buf[c] == '\n')
         ++nbLines;

   int* plenghts = new int[nbLines];
   int line = 0;
   int oldpos = 0;
   for (c = 0; c < len; ++c)
   {
      if (buf[c] == '\n')
      {
         buf[c] = '\0';  // inutile en fait, mais pour le geste
         plenghts[line] = c - oldpos;
         oldpos = c + 1;
         ++line;
      }
   }
   plenghts[line] = c - oldpos;  // dernière ligne

   // affichage:
   glListBase(listBase);
   int offset = 0;
   for (line = 0; line < nbLines; ++line)
   {
      glPushMatrix();
      glTranslatef(0, -line * feedJump, 0);
      glCallLists(plenghts[line], GL_UNSIGNED_BYTE, buf + offset);  // poum tout d'un coup
      offset += plenghts[line] + 1;
      glPopMatrix();
   }

   delete [] plenghts;

   glPopAttrib();
}

// affiche dans l'espace non projeté
void GPFont::Print2D(const char* fmt, ...)
{
   if (!loaded)
      return;

   PushScreenCoordinateMatrix();
   va_list vl;
   va_start(vl, fmt);
   PrintCmn(fmt, vl);
   va_end(vl);
   PopProjectionMatrix();
}

// affiche dans l'espace sans modifier la caméra
void GPFont::Print3D(const char* fmt, ...)
{
   if (!loaded)
      return;

   va_list vl;
   va_start(vl, fmt);
   PrintCmn(fmt, vl);
   va_end(vl);
}

GPFont::~GPFont()
{
   if (loaded)
   {
      glDeleteLists(listBase, 256);
      glDeleteTextures(256, texNames);
   }
}


// -----------  -----------
// fonctions opengl
// -----------  -----------

void PushScreenCoordinateMatrix(void)  // projection orthogonale
{
   glPushAttrib(GL_TRANSFORM_BIT);
   GLint viewport[4];
   glGetIntegerv(GL_VIEWPORT, viewport);
   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
   glLoadIdentity();
   glOrtho(viewport[0], viewport[2], viewport[1], viewport[3], -1000, 1000);
   glPopAttrib();
}

void PopProjectionMatrix(void)
{
   glPushAttrib(GL_TRANSFORM_BIT);
   glMatrixMode(GL_PROJECTION);
   glPopMatrix();
   glPopAttrib();
}

}
