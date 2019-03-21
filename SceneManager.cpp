#include "SceneManager.hpp"

std::vector<std::shared_ptr<Model>> SceneManager::toRender;

void SceneManager::addRenderModel(std::shared_ptr<Model> m)
{
    SceneManager::toRender.push_back(std::move(m));
}

void SceneManager::displayCallback()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    gluPerspective(10.0, 16.0f/9.0f, 0.1f, 100.0f);
    gluLookAt(
        0.0, 0.0, -10.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0
    );
    
    for(auto m : toRender)
    {
        m->draw();
    }

    glFlush();
}