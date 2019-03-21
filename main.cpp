#include <GL/gl.h>
#include <GL/glut.h>

#include "Input.hpp"
#include "SceneManager.hpp"


void init (void) 
{
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);
/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
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
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1280, 720); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("HW#1");
    init ();

    std::unique_ptr<Object> obj(std::make_unique<Object>());
    std::shared_ptr<Model> model(std::make_shared<Model>(move(obj)));
    SceneManager::addRenderModel(model);

    glutDisplayFunc(SceneManager::displayCallback); 
    glutKeyboardFunc(keyboardFunc);
    glutMainLoop();
    return 0;  
}