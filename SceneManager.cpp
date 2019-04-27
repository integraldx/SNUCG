#include "SceneManager.hpp"

std::pair<int, int> SceneManager::screenScale;
std::vector<std::shared_ptr<Model>> SceneManager::toRender;
Camera SceneManager::cam;
int SceneManager::window;
std::chrono::duration<long, std::milli> SceneManager::startTime;
bool SceneManager::isLeftMouseDown;
std::pair<int, int> SceneManager::initialMousePosition;

void SceneManager::initializeScene(std::string s)
{
    auto splineParser = SplineParser::parseFile(s);
    std::shared_ptr<Object> o = splineParser.generateObject(10);
    std::shared_ptr<Model> m = std::make_shared<Model>(o);
    addRenderModel(m);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize (1000, 1000); 
    screenScale = {1000, 1000};
    glutInitWindowPosition (50, 50);
    SceneManager::setWindow(glutCreateWindow ("HW3"));
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    GLfloat ambient[] = {0.1, 0.1, 0.1, 0.1};
    GLfloat position[] = {10, 10, 10, 1};
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LESS);
/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glutDisplayFunc(displayCallback); 
    glutKeyboardFunc(keyboardCallback);
    glutMouseFunc(mouseCallback);
    glutMotionFunc(motionCallback);
    initTime();

    timerCallback(0);
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

    // glPushMatrix();
    // {
    //     glColor4f(0.9, 0.9, 0.9, 0.0);
    //     auto cen = cam.getCenter();
    //     glTranslatef(cen.x, cen.y, cen.z);
    //     glutSolidSphere(2.5, 20, 100);
    // }
    // glPopMatrix();

    glutSwapBuffers();
    glFlush();
}

void SceneManager::keyboardCallback(unsigned char key, int mousex, int mousey)
{
    switch(key)
    {
        case 'w':
        case 'W':
            cam.setCenter(cam.getCenter() + cam.getLookDirection() * 0.1);
            break;
        case 's':
        case 'S':
            cam.setCenter(cam.getCenter() - cam.getLookDirection() * 0.1);
            break;
        case 'a':
        case 'A':
            cam.setCenter(cam.getCenter() + crossProduct(cam.getUp(), cam.getLookDirection()) * 0.1);
            break;
        case 'd':
        case 'D':
            cam.setCenter(cam.getCenter() - crossProduct(cam.getUp(), cam.getLookDirection()) * 0.1);
            break;

        case 'r':
        case 'R':
            cam.setRotation({1, 0, 0, 0});
            cam.setFOV(60);
            cam.setZoom(5);
            cam.setCenter({0, 0, 0});
            break;
        case 'x':
        case 'X':
            glutDestroyWindow(window);
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

void SceneManager::mouseCallback(int button, int state, int x, int y)
{
    int mod = glutGetModifiers();
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                isLeftMouseDown = true;
                initialMousePosition = {x, screenScale.second - y};
            }
            else if (state = GLUT_UP)
            {
                isLeftMouseDown = false;
            }
            break;
    
        // case GLUT_RIGHT_BUTTON:

        //     break;
        // case GLUT_MIDDLE_BUTTON:

        //     break;
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
    y = screenScale.second - y;
    float rate = 0.003;
    if(isLeftMouseDown)
    {
        cam.applyDeltaRotationByAngle(-(x - initialMousePosition.first) * rate , -(y - initialMousePosition.second) * rate);
    }
    initialMousePosition = {x, y};
}

void SceneManager::setWindow(int newWindow)
{
    window = newWindow;
}

void SceneManager::initTime()
{
    startTime = std::chrono::duration_cast<std::chrono::duration<long, std::milli>>(std::chrono::system_clock::now().time_since_epoch());
}
