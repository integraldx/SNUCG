#pragma once

#include <iostream>
#include "Vector3f.hpp"
#include "math.h"
#include "Quaternion.hpp"

class Camera
{
private:
    float zoom = 3;
    Quaternion orientation = {1, 0, 0, 0};
    float fov = 60;
    
public:
    void applyDeltaZoom(float zoom);
    Vector3f rotateViewplaneToVector(Vector3f v);

    Vector3f getLookDirection();

    Vector3f getPosition();
    void applyDeltaRotation(Quaternion q);

    Vector3f getUp();

    float getFOV();
    void setFOV(float f);
    void applyDeltaFOV(float delta);
};