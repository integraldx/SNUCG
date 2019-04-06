#pragma once

#include "Vector3f.hpp"
#include "Quaternion.hpp"
#include <memory>
#include "Object.hpp"
#include <GL/gl.h>

class Model
{
protected:
    Vector3f position = {0, 0, 0};
    Quaternion rotation = identityQuat();
    Vector3f scale = {1, 1, 1};
    std::shared_ptr<Object> root;

public:
    Model(std::shared_ptr<Object>);
    ~Model();
    void draw();
    void setPosition(Vector3f);
    void setRotation(float, Vector3f);
    void applyDeltaRotation(Quaternion q);
    void setScale(Vector3f);
};
