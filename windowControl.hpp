#include "Includes/GLFW/glfw3.h"

namespace SNUCG
{
    /// Init GLFW and get window.
    GLFWwindow* initGlfwEnviornment(int width, int height, const char* title)
    {
        GLFWwindow* toReturn = nullptr;
        if(!glfwInit())
        {
            return NULL;
        }

        toReturn = glfwCreateWindow(width, height, title, NULL, NULL);

        if(!toReturn)
        {
            glfwTerminate();
        }

        glfwMakeContextCurrent(toReturn);

        return toReturn;
    }

    /// Ends GLFW library.
    /// Same as glfwTerminate() 
    void endGlfwEnviornment()
    {
        glfwTerminate();
    }
}
