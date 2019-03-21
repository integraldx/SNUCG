#pragma once

#include <vector>
#include "Util.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <memory>

class Object
{
private:
    std::vector<Vec3> vertices;
    Vec3 position = {0, 0, 0};
    Vec3 rotationCenter = {0, 0, 0};
    Vec3 rotationAxis = {0, 0, 0};
    float rotationAngle = 0;
    Vec3 scale = {1, 1, 1};

    Vec3 color = {1, 1, 1};
    std::vector<std::unique_ptr<Object>> childs;

public:
    Object();
    Object(std::vector<Vec3> vertices);
    ~Object();
    void draw();
    void setPosition(Vec3);
    void setRotationCenter(Vec3);
    void setRotation(float, Vec3);
    void setScale(Vec3);
    void setColor(Vec3);
    void addChild(std::unique_ptr<Object>);
};