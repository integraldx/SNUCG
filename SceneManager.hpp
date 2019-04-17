#pragma once

#include <vector>
#include <memory>
#include "Model.hpp"
#include "Camera.hpp"
#include "Pod.hpp"
#include <time.h>
#include <chrono>
#include <algorithm>
#include "Quaternion.hpp"

class SceneManager
{
private:
    static std::pair<int, int> screenScale;
    static std::vector<std::shared_ptr<Model>> toRender;
    static Camera cam;
    static std::shared_ptr<Pod> pod;
    static int window;
    static std::chrono::duration<long, std::milli> startTime;
    static bool isLeftMouseDown;
    static std::pair<int, int> initialMousePosition;
    static int homeworkNumber;

public:
    static void initializeScene(int);
    static void addRenderModel(std::shared_ptr<Model>);
    static void displayCallback();
    static void keyboardCallback(unsigned char, int, int);
    static void timerCallback(int);
    static void mouseCallback(int button, int state, int x, int y);
    static void motionCallback(int x, int y);
    static void setPod(std::shared_ptr<Pod> p);
    static void animatePod(int);
    static void setWindow(int);
    static void initTime();
};