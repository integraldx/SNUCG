#include "SceneManager.hpp"

std::pair<int, int> SceneManager::screenScale;
std::vector<std::shared_ptr<Model>> SceneManager::toRender;
Camera SceneManager::cam;
int SceneManager::window;
std::chrono::duration<long, std::milli> SceneManager::startTime;
bool SceneManager::isLeftMouseDown;
std::pair<int, int> SceneManager::initialMousePosition;
std::string SceneManager::splineFileName;

void SceneManager::initializeScene(std::string s)
{
    splineFileName = std::string(s);
    setInitialObjects();
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize (1000, 1000); 
    screenScale = {1000, 1000};
    glutInitWindowPosition (50, 50);
    SceneManager::setWindow(glutCreateWindow("HW4"));
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    setLightingEnviornment();
    glShadeModel(GL_SMOOTH);
    glDepthFunc(GL_LESS);
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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

void SceneManager::setLightingEnviornment()
{
    glEnable(GL_LIGHTING);
    // Light 0
    {
        GLfloat ambient[] = {0.1, 0.1, 0.1, 0.1};
        GLfloat position[] = {500, 1000, 1000, 1};
        GLfloat lightColor[] = {1.0, 0.7, 0.7, 1};
        GLfloat specular[] = {1, 1, 1, 1};
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        glLightfv(GL_LIGHT0, GL_POSITION, position);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
        glEnable(GL_LIGHT0);
    }

    // Light 1
    {
        GLfloat ambient[] = {0.1, 0.1, 0.1, 0.1};
        GLfloat position[] = {-1000, 1000, 0, 1};
        GLfloat lightColor[] = {0.7, 1.0, 0.7, 1};
        GLfloat specular[] = {1, 1, 1, 1};
        glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
        glLightfv(GL_LIGHT1, GL_POSITION, position);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor);
        glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
        glEnable(GL_LIGHT1);
    }

    // Light 2
    {
        GLfloat ambient[] = {0.1, 0.1, 0.1, 0.1};
        GLfloat position[] = {500, 1000, -1000, 1};
        GLfloat lightColor[] = {0.7, 0.7, 1.0, 1};
        GLfloat specular[] = {1, 1, 1, 1};
        glLightfv(GL_LIGHT2, GL_AMBIENT, ambient);
        glLightfv(GL_LIGHT2, GL_POSITION, position);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor);
        glLightfv(GL_LIGHT2, GL_SPECULAR, specular);
        glEnable(GL_LIGHT2);
    }
}

void SceneManager::setInitialObjects()
{
    // Splined Object
    {
        auto splineParser = SplineParser::parseFile(splineFileName);
        std::shared_ptr<Object> o = splineParser.generateObject(30);
        Material mat;
        mat.setSpecular({1, 1, 1, 1.0});
        mat.setShininess(128);
        o->setMaterial(mat);
        std::shared_ptr<Model> m = std::make_shared<Model>(o);
        addRenderModel(m);
    }

    {
        std::vector<Vector3f> planeV;
        planeV.push_back({100, -50, 100});
        planeV.push_back({100, -50, -100});
        planeV.push_back({-100, -50, -100});
        planeV.push_back({100, -50, 100});
        planeV.push_back({-100, -50, -100});
        planeV.push_back({-100, -50, 100});

        std::shared_ptr<Object> o = std::make_shared<Object>(planeV);
        Material mat;
        mat.setDiffuse({0.4, 0.4, 0.4, 1});
        o->setMaterial(mat);
        std::shared_ptr<Model> m = std::make_shared<Model>(o);
        addRenderModel(m);
    }
}

void SceneManager::addRenderModel(std::shared_ptr<Model> m)
{
    SceneManager::toRender.push_back(std::move(m));
}

void SceneManager::displayCallback()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluPerspective(cam.getFOV(), (float)screenScale.first / screenScale.second, 0.1f, 10000.0f);
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

    renderMaterialedSpheres();

    glutSwapBuffers();
    glFlush();
}

void SceneManager::renderMaterialedSpheres()
{
    // 1
    {
        glPushMatrix();
        glTranslatef(15, 0, 0);
        Material mat;

        mat.applyMaterial();
        glutSolidSphere(5, 20, 20);

        glPopMatrix();
    }

    // 2
    {
        glPushMatrix();
        glTranslatef(30, 0, 0);
        Material mat;

        mat.applyMaterial();
        glutSolidSphere(5, 20, 20);

        glPopMatrix();
    }

    // 3
    {
        glPushMatrix();
        glTranslatef(20, -10, 10);
        Material mat;

        mat.applyMaterial();
        glutSolidSphere(5, 20, 20);

        glPopMatrix();
    }

    // 4
    {
        glPushMatrix();
        glTranslatef(-15, 0, 0);
        Material mat;

        mat.applyMaterial();
        glutSolidSphere(5, 20, 20);

        glPopMatrix();
    }

    // 5
    {
        glPushMatrix();
        glTranslatef(-30, 0, 0);
        Material mat;

        mat.applyMaterial();
        glutSolidSphere(5, 20, 20);

        glPopMatrix();
    }

    // 6
    {
        glPushMatrix();
        glTranslatef(-20, -10, 10);
        Material mat;

        mat.applyMaterial();
        glutSolidSphere(5, 20, 20);

        glPopMatrix();
    }

    // 7
    {
        glPushMatrix();
        glTranslatef(5, 5, 5);
        Material mat;
        mat.setDiffuse({1, 1, 1, 0.4});

        mat.applyMaterial();
        glutSolidSphere(5, 20, 20);

        glPopMatrix();
    }
}

void SceneManager::keyboardCallback(unsigned char key, int mousex, int mousey)
{
    switch(key)
    {
        case 'w':
        case 'W':
            cam.setCenter(cam.getCenter() + cam.getLookDirection());
            break;
        case 's':
        case 'S':
            cam.setCenter(cam.getCenter() - cam.getLookDirection());
            break;
        case 'a':
        case 'A':
            cam.setCenter(cam.getCenter() + crossProduct(cam.getUp(), cam.getLookDirection()));
            break;
        case 'd':
        case 'D':
            cam.setCenter(cam.getCenter() - crossProduct(cam.getUp(), cam.getLookDirection()));
            break;

        // case 'r':
        // case 'R':
        //     cam.setRotation({1, 0, 0, 0});
        //     cam.setFOV(60);
        //     cam.setZoom(5);
        //     cam.setCenter({0, 0, 100});
        //     break;
        case 'x':
        case 'X':
            glutDestroyWindow(window);
            exit(0);
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
