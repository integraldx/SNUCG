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
    glEnable(GL_LIGHTING);
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
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    timerCallback(0);
}

void SceneManager::setLightingEnviornment()
{
    // Light 0
    {
        GLfloat ambient[] = {0.2, 0.2, 0.2, 1};
        GLfloat position[] = {50, 100, 100, 1};
        GLfloat lightColor[] = {1.0, 0.8, 0.8, 1};
        GLfloat specular[] = {1, 0.9, 0.9, 1};
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        glLightfv(GL_LIGHT0, GL_POSITION, position);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    }

    // Light 1
    {
        GLfloat ambient[] = {0.2, 0.2, 0.2, 1};
        GLfloat position[] = {-100, 100, 0, 1};
        GLfloat lightColor[] = {0.8, 1.0, 0.8, 1};
        GLfloat specular[] = {0.9, 1, 0.9, 1};
        glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
        glLightfv(GL_LIGHT1, GL_POSITION, position);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor);
        glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
    }

    // Light 2
    {
        GLfloat ambient[] = {0.2, 0.2, 0.2, 1};
        GLfloat position[] = {50, 100, -100, 1};
        GLfloat lightColor[] = {0.8, 0.8, 1.0, 1};
        GLfloat specular[] = {0.9, 0.9, 1, 1};
        glLightfv(GL_LIGHT2, GL_AMBIENT, ambient);
        glLightfv(GL_LIGHT2, GL_POSITION, position);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor);
        glLightfv(GL_LIGHT2, GL_SPECULAR, specular);
    }
}

void SceneManager::setInitialObjects()
{
    // Splined Object
    {
        auto splineParser = SplineParser::parseFile(splineFileName);
        std::shared_ptr<Object> o = splineParser.generateObject(35);
        Material mat;
        mat.setDiffuse({0.5, 0.5, 0.5, 1});
        mat.setSpecular({1, 1, 1, 1.0});
        mat.setEmission({0.1, 0.1, 0.1, 1});
        mat.setShininess(30);
        o->setMaterial(mat);
        std::shared_ptr<Model> m = std::make_shared<Model>(o);
        addRenderModel(m);
    }

    {
        std::vector<Vector3f> planeV;
        planeV.push_back({100, -30, 100});
        planeV.push_back({100, -30, -100});
        planeV.push_back({-100, -30, -100});
        planeV.push_back({100, -30, 100});
        planeV.push_back({-100, -30, -100});
        planeV.push_back({-100, -30, 100});

        std::shared_ptr<Object> o = std::make_shared<Object>(planeV);
        Material mat;
        mat.setDiffuse({0.4, 0.4, 0.4, 1});
        mat.setSpecular({0.1, 0.1, 0.1, 1});
        mat.setShininess(5);
        o->setMaterial(mat);
        std::shared_ptr<Model> m = std::make_shared<Model>(o);
        addRenderModel(m);
    }

    renderMaterialedSpheres();
}

void SceneManager::addRenderModel(std::shared_ptr<Model> m)
{
    SceneManager::toRender.push_back(std::move(m));
}

void SceneManager::displayCallback()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(cam.getFOV(), (float)screenScale.first / screenScale.second, 0.1f, 10000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    Vector3f camPosition = cam.getPosition();
    Vector3f camDirection = cam.getLookDirection();
    Vector3f camUp = cam.getUp();
    gluLookAt(
        camPosition.x, camPosition.y, camPosition.z,
        camPosition.x + camDirection.x, camPosition.y + camDirection.y, camPosition.z + camDirection.z,
        camUp.x, camUp.y, camUp.z
    );
    
    setLightingEnviornment();
    for(auto m : toRender)
    {
        m->draw();
    }


    glutSwapBuffers();
    glFlush();
}

void SceneManager::renderMaterialedSpheres()
{
    // 1
    {
        auto sp = std::static_pointer_cast<Object>(std::make_shared<SphereObject>());
        sp->setScale({5, 5, 5});
        Material mat;
        mat.setDiffuse({0.2, 0.2, 0.2, 1});
        mat.setSpecular({0.8, 0.8, 0.8, 0.8});
        mat.setShininess(12);
        sp->setMaterial(mat);

        auto mod = std::make_shared<Model>(sp);
        mod->setPosition({15, 0, 0});
        addRenderModel(mod);
    }

    // 2
    {
        auto sp = std::static_pointer_cast<Object>(std::make_shared<SphereObject>());
        sp->setScale({5, 5, 5});
        Material mat;
        mat.setDiffuse({0.3, 0.3, 0.6, 1});
        mat.setSpecular({0.5, 0.5, 0.5, 1});
        mat.setShininess(50);
        sp->setMaterial(mat);

        auto mod = std::make_shared<Model>(sp);
        mod->setPosition({30, 0, 0});
        addRenderModel(mod);
    }

    // 3
    {
        auto sp = std::static_pointer_cast<Object>(std::make_shared<SphereObject>());
        sp->setScale({5, 5, 5});
        Material mat;
        mat.setDiffuse({0.8, 0.6, 0.6, 1});
        mat.setAmbient({0.1, 0.1, 0.1, 1});
        mat.setSpecular({0.2, 0.2, 0.2, 0.2});
        mat.setShininess(30);
        sp->setMaterial(mat);

        auto mod = std::make_shared<Model>(sp);
        mod->setPosition({20, -10, 10});
        addRenderModel(mod);
    }

    // 4
    {
        auto sp = std::static_pointer_cast<Object>(std::make_shared<SphereObject>());
        sp->setScale({5, 5, 5});
        Material mat;
        mat.setDiffuse({0.4, 0.2, 0.2, 1});
        mat.setSpecular({0.1, 0.1, 0.1, 1});
        mat.setShininess(10);
        sp->setMaterial(mat);

        auto mod = std::make_shared<Model>(sp);
        mod->setPosition({-15, 0, 0});
        addRenderModel(mod);
    }

    // 5
    {
        auto sp = std::static_pointer_cast<Object>(std::make_shared<SphereObject>());
        sp->setScale({5, 5, 5});
        Material mat;
        mat.setDiffuse({0.05, 0.05, 0.05, 1});
        mat.setAmbient({0.01, 0.01, 0.01, 1});
        mat.setSpecular({0.2, 0.2, 0.2, 1});
        mat.setShininess(10);
        sp->setMaterial(mat);

        auto mod = std::make_shared<Model>(sp);
        mod->setPosition({-30, 0, 0});
        addRenderModel(mod);
    }

    // 6
    {
        auto sp = std::static_pointer_cast<Object>(std::make_shared<SphereObject>());
        sp->setScale({5, 5, 5});
        Material mat;
        mat.setDiffuse({0.4, 0.8, 0.4, 0.7});
        mat.setSpecular({0.2, 0.4, 0.2, 1});
        mat.setShininess({76});
        mat.setEmission({0.1, 0.2, 0.1, 0});
        sp->setMaterial(mat);

        auto mod = std::make_shared<Model>(sp);
        mod->setPosition({-20, -10, 10});
        addRenderModel(mod);
    }

    // 7
    {
        auto sp = std::static_pointer_cast<Object>(std::make_shared<SphereObject>());
        sp->setScale({5, 5, 5});
        Material mat;
        mat.setDiffuse({0.8, 0.3, 0.3, 0.4});
        sp->setMaterial(mat);

        auto mod = std::make_shared<Model>(sp);
        mod->setPosition({5, 5, 5});
        addRenderModel(mod);
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
