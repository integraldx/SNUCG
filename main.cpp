#include <GL/gl.h>
#include <GL/glut.h>

#include "SceneManager.hpp"


void init (void) 
{
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);
/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

/* 
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1280, 720); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("HW#1");
    init ();

    std::vector<Vec3> v;

    std::unique_ptr<Object> center(std::make_unique<Object>(v));

    std::vector<Vec3> redV;
    redV.push_back({1.0, 1.0, 0});
    redV.push_back({1.0, 0.0, 0});
    redV.push_back({0.0, 0.0, 0});
    redV.push_back({0.0, 1.0, 0});

    std::vector<Vec3> blueV;
    blueV.push_back({1.0, -1.0, 0});
    blueV.push_back({1.0, 0.0, 0});
    blueV.push_back({0.0, 0.0, 0});
    blueV.push_back({0.0, -1.0, 0});
    
    std::vector<Vec3> yellowV;
    yellowV.push_back({-1.0, -1.0, 0});
    yellowV.push_back({-1.0, 0.0, 0});
    yellowV.push_back({0.0, 0.0, 0});
    yellowV.push_back({0.0, -1.0, 0});

    std::vector<Vec3> greenV;
    greenV.push_back({-1.0, 1.0, 0});
    greenV.push_back({-1.0, 0.0, 0});
    greenV.push_back({0.0, 0.0, 0});
    greenV.push_back({0.0, 1.0, 0});

    std::unique_ptr<Object> red(std::make_unique<Object>(redV));
    red->setColor({1.0, 0, 0});
    std::unique_ptr<Object> blue(std::make_unique<Object>(blueV));
    blue->setColor({0, 0, 1});
    std::unique_ptr<Object> yellow(std::make_unique<Object>(yellowV));
    yellow->setColor({1, 1, 0});
    std::unique_ptr<Object> green(std::make_unique<Object>(greenV));
    green->setColor({0, 1, 0});

    center->addChild(std::move(red));
    center->addChild(std::move(blue));
    center->addChild(std::move(yellow));
    center->addChild(std::move(green));

    std::shared_ptr<Model> model(std::make_shared<Model>(move(center)));
    SceneManager::addRenderModel(model);

    glutDisplayFunc(SceneManager::displayCallback); 
    glutKeyboardFunc(SceneManager::keyboardCallback);
    glutMainLoop();
    return 0;  
}