

#include "GraphicEngine.h"
#include "Scene.h"
#include "Camera.h"
#include "Object.h"

namespace Engine
{
    GraphicEngine::GraphicEngine(string name,unsigned int w, unsigned int h,unsigned int nbCamera,unsigned int nbScene)
    {

        SDL_Init(SDL_INIT_VIDEO);
		atexit(SDL_Quit);

        SDL_WM_SetCaption(name.c_str(),NULL);
        SDL_SetVideoMode(w, h, 32, SDL_OPENGL);

		//D'autre options
		/*glMatrixMode( GL_PROJECTION );
		glLoadIdentity();
		gluPerspective(70,(double)640/480,1,1000);
		glEnable(GL_DEPTH_TEST);
		SDL_WM_GrabInput(SDL_GRAB_ON);
		SDL_ShowCursor(SDL_DISABLE);*/

        //camera =vector<Camera*>;
       // scene = vector<Scene*>;

        /**
        Ajout d'une scene par defaut
        **/
        this->scene.push_back(new Scene(TS_Static));
    }

    GraphicEngine::~GraphicEngine()
    {
        //TODO libérer chaque scene et caméra
        SDL_Quit();
    }

    unsigned int GraphicEngine::addCamera(Camera *camera)
    {
        this->camera.push_back(camera);

        //Retourne l'id de la nouvelle camera
        return this->camera.size()-1;
    }

    unsigned int GraphicEngine::addScene(Scene *scene)
    {
        this->scene.push_back(scene);

        //Retourne l'id de la nouvelle scene
        return this->scene.size()-1;
    }

    void GraphicEngine::addSceneObject(Object *object,unsigned idScene)
    {
        this->scene[idScene]->addObject(object);
    }

    void GraphicEngine::addSceneObject(Object *object,Scene *scene)
    {
        scene->addObject(object);
    }

    void GraphicEngine::draw(Camera *camera)
    {
		//on vide les buffer
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		//donne le type de matrice a utiliser
		glMatrixMode( GL_MODELVIEW );
		//charge la matrice identité
		glLoadIdentity( );
		
		//Mise à jours de la caméra
        camera->draw();

			glBegin(GL_LINES);
			glColor3ub(0,0,255);
			glVertex3d(0,0,0);
			glVertex3d(4,0,0);
			glColor3ub(0,255,0);
			glVertex3d(0,0,0);
			glVertex3d(0,4,0);
			glEnd();
        //Mise à jours des scenes
        vector<Scene*>::iterator it;

        for ( it=scene.begin() ; it < scene.end(); it++ )
        {
            (*it)->draw();
        }


		//signale la fin du traçage
		glFlush(); 
		//actualise l'image
		SDL_GL_SwapBuffers();
    }

    void GraphicEngine::draw(unsigned int idCamera)
    {
        this->draw(this->camera[idCamera]);
    }
}//namespace Engine
