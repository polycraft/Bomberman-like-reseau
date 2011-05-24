#include "polices.h"



#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <math.h>

using namespace Engine;

struct ModeParams
{
      int resx, resy;
      int colorDepth;
      long flags;
      int fov;
      char* winName;
};
int InitializeGL(const ModeParams& mode);
bool EscapeRead(void);
int exemple();
