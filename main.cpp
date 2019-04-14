#include <GL/gl.h>
#include <GL/glut.h>

#include "SceneManager.hpp"
#include "Pod.hpp"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    SceneManager::initializeScene();

    std::shared_ptr<Pod> model = Pod::getPod();
    SceneManager::addRenderModel(model->getModel());
    SceneManager::setPod(model);
    SceneManager::timerCallback(0);
    glutMainLoop();
    return 0;  
}