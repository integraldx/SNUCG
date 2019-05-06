#pragma once

#include <iostream>
#include "Vectorf.hpp"
#include "math.h"
#include "Quaternion.hpp"

class Camera
{
private:
    float zoom = 5;
    Quaternion orientation = {1, 0, 0, 0};
    Vector3f center = {0, 10, 100};
    std::pair<float, float> panValue = {0, 0};
    float fov = 60;
    
public:
    void applyDeltaZoom(float zoom);
    void setZoom(float f);
    Vector3f rotateViewplaneToVector(Vector3f v);

    Vector3f getLookDirection();

    Vector3f getPosition();
    void applyDeltaRotation(Quaternion q);
    void applyDeltaRotationByAngle(float horizontal, float vertical);
    void setRotation(Quaternion q);

    Vector3f getUp();

    float getFOV();
    void setFOV(float f);
    void applyDeltaFOV(float delta);

    void applyDeltaPan(float x, float y);
    void setCenter(Vector3f);
    Vector3f getCenter();
};