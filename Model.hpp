#pragma once

#include "Vector3f.hpp"
#include <memory>
#include "Object.hpp"
#include <GL/gl.h>

class Model
{
protected:
    Vector3f position = {0, 0, 0};
    Vector3f rotationAxis = {0, 0, 0};
    float rotationAngle = 0;
    Vector3f scale = {1, 1, 1};
    std::shared_ptr<Object> root;

public:
    Model(std::shared_ptr<Object>);
    ~Model();
    void draw();
    void setPosition(Vector3f);
    void setRotation(float, Vector3f);
    void setScale(Vector3f);
};
