#pragma once

#include <iostream>
#include "Util.hpp"
#include "math.h"

class Camera
{
    float viewAngle = 0;
    Vec3 position = {0, 0, -5};
    Vec3 lookDirection = {0, 0, 1};
    Vec3 up = {0, 1, 0};
    
public:
    void applyDeltaPosition(Vec3);
    void rotateLookDirection(float angle);
    Vec3 getLookDirection();
    Vec3 getPosition();
    Vec3 getUp();
};