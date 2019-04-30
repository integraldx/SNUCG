#include "SceneManager.hpp"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    std::string s;
    std::cin >> s;

    SceneManager::initializeScene(s);
    glutMainLoop();
    return 0;  
}