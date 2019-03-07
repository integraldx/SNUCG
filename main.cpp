#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "windowControl.hpp"

int main()
{
    GLFWwindow* window = SNUCG::initGlfwEnviornment(1280, 960, "Hello World!");

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON);
    {
        glVertex3f (0.25, 0.25, 0.0);
        glVertex3f (0.75, 0.25, 0.0);
        glVertex3f (0.75, 0.75, 0.0);
        glVertex3f (0.25, 0.75, 0.0);
    }
    glEnd();
    glFlush();

    GLuint VertexArrayID;
    

    while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
    {
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    SNUCG::endGlfwEnviornment();
    return 0;
}