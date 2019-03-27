#pragma once

#include <vector>
#include <memory>
#include "Model.hpp"
#include "Camera.hpp"
#include "Pod.hpp"
#include <time.h>
#include <chrono>

class SceneManager
{
private:
    static std::vector<std::shared_ptr<Model>> toRender;
    static Camera cam;
    static std::shared_ptr<Pod> pod;

public:
    static void addRenderModel(std::shared_ptr<Model>);
    static void displayCallback();
    static void keyboardCallback(unsigned char, int, int);
    static void timerCallback(int);
    static void setPod(std::shared_ptr<Pod> p);
    static void animatePod(int);
};