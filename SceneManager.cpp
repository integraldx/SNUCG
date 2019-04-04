#include "SceneManager.hpp"

std::vector<std::shared_ptr<Model>> SceneManager::toRender;
Camera SceneManager::cam;
std::shared_ptr<Pod> SceneManager::pod(nullptr);
int SceneManager::window;
std::chrono::duration<long, std::milli> SceneManager::startTime;

void SceneManager::addRenderModel(std::shared_ptr<Model> m)
{
    SceneManager::toRender.push_back(std::move(m));
}

void SceneManager::displayCallback()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluPerspective(60.0, 16.0f/9.0f, 0.1f, 100.0f);
    Vector3f camPosition = cam.getPosition();
    Vector3f camDirection = cam.getLookDirection();
    gluLookAt(
        camPosition.x, camPosition.y, camPosition.z,
        camPosition.x + camDirection.x, camPosition.y + camDirection.y, camPosition.z + camDirection.z,
        0.0, 1.0, 0.0
    );
    
    for(auto m : toRender)
    {
        m->draw();
    }
    glutSwapBuffers();
    glFlush();
}

void SceneManager::keyboardCallback(unsigned char key, int mousex, int mousey)
{
    switch(key)
    {
        //case 'w':
        //case 'W':
        //    cam.applyDeltaPosition(normalizeVec3(cam.getLookDirection()) * 0.05);
        //    break;
        //case 's':
        //case 'S':
        //    cam.applyDeltaPosition(normalizeVec3(cam.getLookDirection()) * -0.05);
        //    break;
        //case 'a':
        //case 'A':
        //    cam.applyDeltaPosition(normalizeVec3(crossProduct(cam.getUp(), cam.getLookDirection())) * 0.05);
        //    break;
        //case 'd':
        //case 'D':
        //    cam.applyDeltaPosition(normalizeVec3(crossProduct(cam.getUp(), cam.getLookDirection())) * -0.05);
        //    break;
        //case 'q':
        //case 'Q':
        //    cam.rotateLookDirection(1);
        //    break;
        //case 'e':
        //case 'E':
        //    cam.rotateLookDirection(-1);
        //    break;
        //case 'i':
        //case 'I':
        //    cam.applyDeltaPosition({0, 0.05, 0});
        //    break;
        //case 'k':
        //case 'K':
        //    cam.applyDeltaPosition({0, -0.05, 0});
        //    break;
        case 'x':
        case 'X':
            glutDestroyWindow(window);
        default:
            break;
    }

}

void SceneManager::animatePod(int cycleTime = 1500)
{
    auto t = std::chrono::duration_cast<std::chrono::duration<long, std::milli>>(std::chrono::system_clock::now().time_since_epoch());
    int frac = (startTime.count() - t.count()) % cycleTime;
    double angle = (double)frac / cycleTime * M_PI * 2;
    pod->setPosition({0, 0.3 * sin(angle), 0});
    pod->rotateLeftThigh(10 * cos(angle) + 30);
    pod->rotateLeftLeg(10 * sin(angle) - 120);
    pod->rotateRightThigh(-10 * sin(angle) + 30);
    pod->rotateRightLeg(-10 * cos(angle) - 120);
}

void SceneManager::timerCallback(int value)
{
    animatePod();
    glutPostRedisplay();
    glutTimerFunc(1000/60, timerCallback, 0);
}

void SceneManager::setPod(std::shared_ptr<Pod> p)
{
    pod.swap(p);
}

void SceneManager::setWindow(int newWindow)
{
    window = newWindow;
}

void SceneManager::initTime()
{
    startTime = std::chrono::duration_cast<std::chrono::duration<long, std::milli>>(std::chrono::system_clock::now().time_since_epoch());
}