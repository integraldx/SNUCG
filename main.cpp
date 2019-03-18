#include <GL/gl.h>
#include <GL/glut.h>

#include "Display.hpp"
#include "Input.hpp"


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
    glutInitWindowSize (1000, 1000); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(displayFunc); 
    glutKeyboardFunc(keyboardFunc);
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}