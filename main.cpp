#include <GL/gl.h>
#include <GL/glut.h>

#include "SceneManager.hpp"
#include "Pod.hpp"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    std::cout << "Input HW number: ";
    int hwNumber;
    std::cin >> hwNumber;

    SceneManager::initializeScene(hwNumber);
    glutMainLoop();
    return 0;  
}