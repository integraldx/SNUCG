#pragma once

#include <iostream>
#include "Vector3f.hpp"
#include "math.h"

class Camera
{
    float viewAngle = 0;
    Vector3f position = {0, 0, -5};
    Vector3f lookDirection = {0, 0, 1};
    Vector3f up = {0, 1, 0};
    float fov = 45;
    
public:
    void applyDeltaPosition(Vector3f);
    void rotateLookDirection(float angle);
    Vector3f getLookDirection();
    Vector3f getPosition();
    Vector3f getUp();
    float getFOV();
    void applyDeltaFOV(float delta);
};