#pragma once

#include <vector>
#include "Util.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <memory>

class Object
{
protected:
    friend class Model;
    std::vector<Vec3> vertices;
    Vec3 position = {0, 0, 0};
    Vec3 rotationCenter = {0, 0, 0};
    Vec3 rotationAxis = {0, 0, 0};
    float rotationAngle = 0;
    Vec3 scale = {1, 1, 1};
    bool hasColor = false;
    Vec3 color = {1, 1, 1};
    std::vector<std::shared_ptr<Object>> childs;

public:
    Object();
    Object(std::vector<Vec3> vertices);
    ~Object();
    void draw();
    void setPosition(Vec3);
    void setRotationCenter(Vec3);
    void setRotation(float, Vec3);
    void setRotationAngle(float);
    float getRotationAngle();
    void setScale(Vec3);
    void setColor(Vec3);
    void addChild(std::shared_ptr<Object>);
};