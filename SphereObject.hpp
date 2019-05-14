#pragma once
#include "Object.hpp"
#include <GL/freeglut.h>

class SphereObject : public Object
{
    public:
    void draw();
    void setPosition(Vector3f v);
    // void setRotationCenter(Vector3f);
    // void setRotation(Quaternion q);
    // void applyDeltaRotation(Quaternion q);
    // void setRotation(float, Vector3f);
    // float getRotationAngle();
    // Vector3f getRotationAxis();
    void setScale(float f);
    // void setColor(Vector3f);
    // void setMaterial(Material m);
    // void addChild(std::shared_ptr<Object>);
};