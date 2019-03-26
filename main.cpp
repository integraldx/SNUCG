#include <GL/gl.h>
#include <GL/glut.h>

#include "SceneManager.hpp"
#include "Pod.hpp"


void init (void) 
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1280, 720); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("HW#1");
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glutDisplayFunc(SceneManager::displayCallback); 
    glutKeyboardFunc(SceneManager::keyboardCallback);
}

/* 
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    init ();

    std::shared_ptr<Pod> model = Pod::getPod();
    SceneManager::addRenderModel(model->getModel());
    SceneManager::setPod(model);

    SceneManager::timerCallback(0);
    glutMainLoop();
    return 0;  
}