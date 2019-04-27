#include "SceneManager.hpp"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    SceneManager::initializeScene("input.txt");
    glutMainLoop();
    return 0;  
}