#include "SceneManager.hpp"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    if(argc < 2)
    {
        std::cout << "Usage: ./main [input file name]" << std::endl;
        return 0;
    }

    SceneManager::initializeScene(std::string(argv[1]));
    glutMainLoop();
    return 0;  
}