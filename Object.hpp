#pragma once

#include <vector>
#include "Vectorf.hpp"
#include "Quaternion.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <memory>
#include "Material.hpp"

class Object
{
protected:
    friend class Model;
    
    std::vector<Vector3f> vertices;
    Vector3f position = {0, 0, 0};
    Vector3f rotationCenter = {0, 0, 0};
    Quaternion rotation = {1, 0, 0, 0};
    Vector3f scale = {1, 1, 1};
    bool hasColor = false;
    Vector3f color = {1, 1, 1};
    std::vector<std::shared_ptr<Object>> childs;
    Material m;

public:
    Object();
    Object(std::vector<Vector3f> vertices);
    ~Object();
    virtual void draw();
    void setPosition(Vector3f);
    void setRotationCenter(Vector3f);
    void setRotation(Quaternion q);
    void applyDeltaRotation(Quaternion q);
    void setRotation(float, Vector3f);
    float getRotationAngle();
    Vector3f getRotationAxis();
    void setScale(Vector3f);
    void setColor(Vector3f);
    void setMaterial(Material m);
    void addChild(std::shared_ptr<Object>);

};
