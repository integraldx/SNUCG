#pragma once

#include <vector>
#include <memory>
#include "Model.hpp"
#include "Camera.hpp"

class SceneManager
{
private:
    static std::vector<std::shared_ptr<Model>> toRender;
    static Camera cam;

public:
    static void addRenderModel(std::shared_ptr<Model>);
    static void displayCallback();
    static void keyboardCallback(unsigned char, int, int);
    static void timerCallback(int);
};