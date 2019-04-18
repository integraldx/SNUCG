#include "SceneManager.hpp"

std::pair<int, int> SceneManager::screenScale;
std::vector<std::shared_ptr<Model>> SceneManager::toRender;
Camera SceneManager::cam;
std::shared_ptr<Pod> SceneManager::pod;
int SceneManager::window;
std::chrono::duration<long, std::milli> SceneManager::startTime;
bool SceneManager::isLeftMouseDown;
std::pair<int, int> SceneManager::initialMousePosition;
int SceneManager::homeworkNumber;

void SceneManager::initializeScene(int homeworkNumber)
{
    SceneManager::homeworkNumber = homeworkNumber;
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize (1000, 1000); 
    screenScale = {1000, 1000};
    glutInitWindowPosition (50, 50);
    SceneManager::setWindow(glutCreateWindow ("HW#" + homeworkNumber));
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
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
    std::shared_ptr<Pod> model;
    std::vector<Vector3f> v;
    std::shared_ptr<Model> m;
    std::shared_ptr<Object> o;
    switch(homeworkNumber)
    {
        case 1:
        case 2:
            model = Pod::getPod();
            addRenderModel(model->getModel());
            setPod(model);
            break;
        case 3:
            v.push_back({-1, 0, 0});
            v.push_back({0, -1, 0});
            v.push_back({1, 0, 0});
            v.push_back({0, 1, 0});
            v.push_back({-1, 0, 0});
            o = std::dynamic_pointer_cast<Object>(std::make_shared<SplinedObject>(v, 100));
            o->setColor({1, 1, 1});
            m = std::make_shared<Model>(o);
            addRenderModel(m);
            break;
        default:
            exit(-1);
            break;
    }

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

    glPushMatrix();
    {
        glColor4f(0.9, 0.9, 0.9, 0.1);
        auto cen = cam.getCenter();
        glTranslatef(cen.x, cen.y, cen.z);
        glutSolidSphere(2.5, 20, 100);
    }
    glPopMatrix();

    glutSwapBuffers();
    glFlush();
}

void SceneManager::keyboardCallback(unsigned char key, int mousex, int mousey)
{
    switch(key)
    {
        case 'w':
        case 'W':
            cam.applyDeltaPan(0, 0.1);
            break;
        case 's':
        case 'S':
            cam.applyDeltaPan(0, -0.1);
            break;
        case 'a':
        case 'A':
            cam.applyDeltaPan(-0.1, 0);
            break;
        case 'd':
        case 'D':
            cam.applyDeltaPan(0.1, 0);
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

void SceneManager::animatePod(int cycleTime = 1500)
{
    auto t = std::chrono::duration_cast<std::chrono::duration<long, std::milli>>(std::chrono::system_clock::now().time_since_epoch());
    int frac = (startTime.count() - t.count()) % cycleTime;
    double angle = (double)frac / cycleTime * M_PI * 2;
    pod->setPosition({0, 0.3 * sin(angle), 0});
    pod->rotateLeftThigh(- (10 * cos(angle) + 30));
    pod->rotateLeftLeg(10 * sin(angle) + 120);
    pod->rotateRightThigh(- (-10 * sin(angle) + 30));
    pod->rotateRightLeg((10 * cos(angle) - 5) + 120);
}

void SceneManager::timerCallback(int value)
{
    if(homeworkNumber == 1 || homeworkNumber == 2)
    {
        animatePod();
    }
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
    y = screenScale.second - y;
    if(isLeftMouseDown && (abs(initialMousePosition.first - x) > 0 || abs(initialMousePosition.second - y) > 0))
    {
        float z;
        glReadPixels((int)x, (int)y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z); 

        GLdouble projection[16];
        GLdouble modelView[16];
        GLint viewPort[4];

        glGetDoublev(GL_PROJECTION_MATRIX,projection);
        glGetDoublev(GL_MODELVIEW_MATRIX,modelView);
        glGetIntegerv(GL_VIEWPORT,viewPort);
        
        Vector3f current;
        {
            double cx, cy, cz;
            gluUnProject(x, y, z, modelView, projection, viewPort, &cx, &cy, &cz);
            current = {(float)cx, (float)cy, (float)cz};
        }
        if(getScale(current - cam.getCenter()) < 2.5)
        {
            Vector3f prev;
            {
                double cx, cy, cz;
                gluUnProject(initialMousePosition.first, initialMousePosition.second, z, modelView, projection, viewPort, &cx, &cy, &cz);
                prev = {(float)cx, (float)cy, (float)cz};
            }

            Vector3f axis = crossProduct(prev - current, cam.getLookDirection());
            auto quat = expToQuat(getScale(axis), normalize(axis));
           	if(~(isnan(quat.w) || isnan(quat.x) || isnan(quat.y) || isnan(quat.z)))
			{
                cam.applyDeltaRotation(quat);
            }
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
