#pragma once

#include <iostream>
#include "Vector3f.hpp"
#include "math.h"

class Camera
{
    float zoom = 3;
    float viewAngleHorizontal = 0;
    float viewAngleVertical = 0;
    float fov = 45;
    
public:
    void applyDeltaZoom(float zoom);
    void rotateCameraHorizontally(float angle);
    void rotateCameraVertically(float angle);
    Vector3f rotateViewplaneToVector(Vector3f v);
    Vector3f getLookDirection();
    Vector3f getPosition();
    Vector3f getUp();
    float getFOV();
    void applyDeltaFOV(float delta);
};