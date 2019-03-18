#pragma once

#include "Display.hpp"
#include <GL/glu.h>
#include <math.h>



void displayFunc()
{
    glClear (GL_COLOR_BUFFER_BIT);
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    gluPerspective(10, 1, 0, 100);
    glColor3f (1.0, 1.0, 1.0);

    GLUquadric* gluQuad = gluNewQuadric();
    gluSphere(gluQuad, 1, 100, 100);

    glFlush ();
}