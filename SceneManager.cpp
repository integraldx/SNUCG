#include "SceneManager.hpp"

std::vector<std::shared_ptr<Model>> SceneManager::toRender;
Camera SceneManager::cam;

void SceneManager::addRenderModel(std::shared_ptr<Model> m)
{
    SceneManager::toRender.push_back(std::move(m));
}

void SceneManager::displayCallback()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    gluPerspective(60.0, 16.0f/9.0f, 0.1f, 100.0f);
    Vec3 camPosition = cam.getPosition();
    Vec3 camDirection = cam.getLookDirection();
    gluLookAt(
        camPosition.x, camPosition.y, camPosition.z,
        camPosition.x + camDirection.x, camPosition.y + camDirection.y, camPosition.z + camDirection.z,
        0.0, 1.0, 0.0
    );
    
    for(auto m : toRender)
    {
        m->draw();
    }

    glFlush();
    glutPostRedisplay();
}

void SceneManager::keyboardCallback(unsigned char key, int mousex, int mousey)
{
    switch(key)
    {
        case 'w':
        case 'W':
            cam.applyDeltaPosition(normalizeVec3(cam.getLookDirection()) * 0.05);
            break;
        case 's':
        case 'S':
            cam.applyDeltaPosition(normalizeVec3(cam.getLookDirection()) * -0.05);
            break;
        case 'a':
        case 'A':
            cam.applyDeltaPosition(normalizeVec3(crossProduct(cam.getUp(), cam.getLookDirection())) * 0.05);
            break;
        case 'd':
        case 'D':
            cam.applyDeltaPosition(normalizeVec3(crossProduct(cam.getUp(), cam.getLookDirection())) * -0.05);
            break;
        case 'q':
        case 'Q':
            cam.rotateLookDirection(0.5);
            break;
        case 'e':
        case 'E':
            cam.rotateLookDirection(-0.5);
            break;

        default:
            break;
    }

}

void SceneManager::timerCallback(int value)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, timerCallback, 0);
}