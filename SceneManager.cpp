#include "SceneManager.hpp"

std::pair<int, int> SceneManager::screenScale;
std::vector<std::shared_ptr<Model>> SceneManager::toRender;
Camera SceneManager::cam;
std::shared_ptr<Pod> SceneManager::pod;
int SceneManager::window;
std::chrono::duration<long, std::milli> SceneManager::startTime;
bool SceneManager::isLeftMouseDown;
std::pair<int, int> SceneManager::initialMousePosition;

void SceneManager::initializeScene()
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1000, 1000); 
    screenScale = {1000, 1000};
    glutInitWindowPosition (50, 50);
    SceneManager::setWindow(glutCreateWindow ("HW#2"));
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glutDisplayFunc(displayCallback); 
    glutKeyboardFunc(keyboardCallback);
    glutMouseFunc(mouseCallback);
    glutMotionFunc(motionCallback);
    initTime();
}

void SceneManager::addRenderModel(std::shared_ptr<Model> m)
{
    SceneManager::toRender.push_back(std::move(m));
}

void SceneManager::displayCallback()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluPerspective(cam.getFOV(), (float)screenScale.first / screenScale.second, 0.1f, 100.0f);
    Vector3f camPosition = cam.getPosition();
    Vector3f camDirection = cam.getLookDirection();
    Vector3f camUp = cam.getUp();
    gluLookAt(
        camPosition.x, camPosition.y, camPosition.z,
        camPosition.x + camDirection.x, camPosition.y + camDirection.y, camPosition.z + camDirection.z,
        camUp.x, camUp.y, camUp.z
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
            //cam.rotateCameraVertically(+0.07);
            //break;
        //case 's':
        //case 'S':
            //cam.rotateCameraVertically(-0.07);
            //break;
        //case 'a':
        //case 'A':
            //cam.rotateCameraHorizontally(-0.07);
            //break;
        //case 'd':
        //case 'D':
            //cam.rotateCameraHorizontally(+0.07);
            //break;

        case 'r':
        case 'R':
            cam.setRotation({1, 0, 0, 0});
            break;
        case 'x':
        case 'X':
            glutDestroyWindow(window);
            break;
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

void SceneManager::mouseCallback(int button, int state, int x, int y)
{

    int mod = glutGetModifiers();
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                isLeftMouseDown = true;
                initialMousePosition = {x, y};
            }
            else if (state = GLUT_UP)
            {
                isLeftMouseDown = false;
            }
            break;
    
        case GLUT_RIGHT_BUTTON:

            break;
        case GLUT_MIDDLE_BUTTON:

            break;
        case 3:
            if(mod & GLUT_ACTIVE_CTRL)
            {
                cam.applyDeltaFOV(-1);
            }
            else
            {
                cam.applyDeltaZoom(-0.1);
            }
            
            break;

        case 4:
            if(mod & GLUT_ACTIVE_CTRL)
            {
                cam.applyDeltaFOV(+1);
            }
            else
            {
                cam.applyDeltaZoom(0.1);
            }
            
            break;

        default:
            break;
    }
}

void SceneManager::motionCallback(int x, int y)
{
    if(isLeftMouseDown)
    {
        Vector3f axis = crossProduct(cam.rotateViewplaneToVector({-(x - initialMousePosition.first), (y - initialMousePosition.second), 0}), cam.getLookDirection());

        if(~(isnan(axis.x) || isnan(axis.y) || isnan(axis.z)))
        {
			auto quat = expToQuat(getScale(axis) / 500, normalize(axis));
            cam.applyDeltaRotation(quat);
        }
    }
    initialMousePosition = {x, y};
}

void SceneManager::setPod(std::shared_ptr<Pod> p)
{
    pod.swap(p);
    pod->setRotation(M_PI / 2, {0, 1, 0});
}

void SceneManager::setWindow(int newWindow)
{
    window = newWindow;
}

void SceneManager::initTime()
{
    startTime = std::chrono::duration_cast<std::chrono::duration<long, std::milli>>(std::chrono::system_clock::now().time_since_epoch());
}
