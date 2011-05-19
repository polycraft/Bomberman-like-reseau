#include "exemple.h"


int exemple()
{
// ne pas ce soucier non plus
int InitializeGL(const ModeParams& mode);
bool EscapeRead(void);

   // code spécifique à l'exemple
   ModeParams parms;

   parms.resx = 800;
   parms.resy = 600;
   parms.colorDepth = 32;
   parms.fov = 80;
   parms.flags = SDL_OPENGL;
   parms.winName = "fenetre exemple";

   InitializeGL(parms);

   // l'important pour l'exemple commence ici:

   // on instancie une classe qui va gérer une police donnée d'une taille donnée.
   // il sera possible de changer la taille de rendu du texte
   // avec les fonctions opengl, mais la résolution pourra être limitée
   // par une taille d'initialisation trop petite
   // le paramètre de taille est spécifié en 'points', comme un logiciel de traitement de texte.

   GPFont iFont("src/ressource/font/font.ttf", 24);

   // le code suivant vérifie si le chargement s'est correctement déroulé
   // il n'est pas obligatoire de passer par cette étape
   // si vous devez taper un code quick and dirty.

   if (!iFont.WereLoadedOk())
   {
      //MessageBox(NULL, "problème avec les polices. font.ttf n\'existe pas ?", "erreur", 0);
      return 1;
   }
   // la classe est failsafe, si ca n'a pas marché on peut tout de même appeller ses méthodes,
   // rien ne se produit.

   // tant qu'on a pas appuyé sur echap
   while (true)
   {
      // pti netotyage de la surface
      //glClearColor(0, 0, 0, 0);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      
      glLoadIdentity();

      // grâce aux fonctions opengl
      // on peut régler la position du texte, la couleur, la taille, la rotation...
      // il peut être utile d'encadrer les modifications des matrices MODELVIEW
      // par des glPushMatrix et glPopMatrix si nécessaire.


      
	  float wave = 1.5;

      // couleur variable:
     // glColor4f(1, 0, 1, 1);

      // position:
     // glTranslatef(0, 280 + 1 * 100, 0); // (en pixels)

      // redimensionnement:
    //  glScalef(1 + 0.7, wave + 0.7, 0);

      // une petite rotation autours de z:
     // glRotatef(1 * 20 - 10, 0, 0, 1);

      // et voila la fameuse ligne l'affichage:
      // il est possible d'utiliser directement une syntaxe à la "printf"
      iFont.Print2D("%.1f FPS", 1 / wave);

      glLoadIdentity();
      glColor4f(1, 1, 1, 1);
      //glTranslatef(0, 100, 0);

      // et finalement, voici une ligne d'exemple démontrant la possibilité de revenir
      // à la ligne
      

      glLoadIdentity();

      glColor4f(1, 0, 0, 1);

      //glScalef(0.1, 0.1, 0.1);
     // glRotatef(30, 0, 1, 0);

      // on peut régler la hauteur des sauts de lignes !
      float oldfj = iFont.GetFeedJump();
      iFont.SetFeedJump(50);

      // il est aussi possible d'afficher du texte dans l'espace:
      iFont.Print3D("texte en 3D\nsur plusieurs lignes\nil pourrait par exemple\nafficher un générique\nquelconque.\nlaissez libre court\nà votre imagination ;)");

      iFont.SetFeedJump(oldfj);

      // on peut faire un scroller:

      glLoadIdentity();
      glColor4f(1, 1, 0, 1);
	  glScalef(2, 4, 2);
      // 200 pixels par seconde

      


      // encore!

      glLoadIdentity();
      glColor4f(0, 1, 1, 0.4);

      glRotatef(-74, 0, 1, 0);

      glScalef(0.1, 0.1, 0.1);

      iFont.Print3D("wooooaaww, magnifique la lib polices !!");

      // et un dernier pour la route, l'hélicoptère:

      glLoadIdentity();
      glColor4f(0.5, 0.5, 1, 1);

      // pour faire tourner autours du centre:
      int midlen = iFont.GetStringPixelWidth("ca tooourne") / 2;

      glTranslatef(380, 550, 0);



      iFont.Print2D("ca tooourne");


      SDL_GL_SwapBuffers();
   }

   return 0;
}

// code spécifique à l'exemple
// cela peut servir d'inspiration, mais n'est aucunement lié
// à la lib polices:
int InitializeGL(const ModeParams& mode)
{
   SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);


   SDL_WM_SetCaption(mode.winName, NULL);

   //glClearDepth(1.0f);
  // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // correction de perspective lors de la projection des texels
   
  // glViewport(0, 0, mode.resx, mode.resy);
     if (NULL == SDL_SetVideoMode(mode.resx, mode.resy, mode.colorDepth, mode.flags))
   {
      printf("surface non initialisée\n");
      return -1;  // problème.
   }
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

      gluPerspective(mode.fov, mode.resx / (float)mode.resy, 2.0f, 1024.0f);
    //  glMatrixMode(GL_MODELVIEW);
     // glLoadIdentity();
      gluLookAt(10, 0, 10, 0, 0, 0, 0, 0, 1);


 //  glMatrixMode(GL_MODELVIEW);
  // glDisable(GL_CULL_FACE);
  // glDisable(GL_LIGHTING);
   
   return 0;
}

bool EscapeRead(void)
{
   SDL_Event e;
   if (SDL_PollEvent(&e))
   {
	  if (e.type == SDL_KEYDOWN)
	  {
         if (e.key.keysym.sym == SDLK_q || e.key.keysym.sym == SDLK_ESCAPE)
		 {
            return true;
		 }
	  }
   }   
   return false;
}
