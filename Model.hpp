#pragma once

#include "Util.hpp"
#include <memory>
#include "Object.hpp"
#include <GL/gl.h>

class Model
{
private:
    Vec3 position = {0, 0, 0};
    Vec3 rotationAxis = {0, 0, 0};
    float rotationAngle = 0;
    Vec3 scale = {1, 1, 1};
    std::unique_ptr<Object> root;

public:
    Model(std::unique_ptr<Object>);
    ~Model();
    void draw();
    void setPosition(Vec3);
    void setRotation(float, Vec3);
    void setScale(Vec3);
};
