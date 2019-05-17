#pragma once

#include <vector>
#include <memory>
#include "Model.hpp"
#include "Camera.hpp"
#include <time.h>
#include <chrono>
#include <algorithm>
#include "Quaternion.hpp"
#include "SplineParser.hpp"
#include "SphereObject.hpp"
#include "SortedObject.hpp"

class SceneManager
{
private:
    static std::pair<int, int> screenScale;
    static std::vector<std::shared_ptr<Model>> toRender;
    static int window;
    static std::chrono::duration<long, std::milli> startTime;
    static bool isLeftMouseDown;
    static std::pair<int, int> initialMousePosition;
    static std::string splineFileName;

    static void setLightingEnviornment();
    static void setInitialObjects();

public:
    static Camera cam;
    static void initializeScene(std::string);
    static void addRenderModel(std::shared_ptr<Model>);
    static void displayCallback();
    static void keyboardCallback(unsigned char, int, int);
    static void timerCallback(int);
    static void mouseCallback(int button, int state, int x, int y);
    static void motionCallback(int x, int y);
    static void setWindow(int);
    static void initTime();
    static void setMaterialedSpheres();
    static bool depthSortFunc(std::shared_ptr<Model> left, std::shared_ptr<Model> right);
};