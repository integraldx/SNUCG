#pragma once
#include "Vector3f.hpp"
#include <math.h>

struct Quaternion
{
    float w;
    float x;
    float y;
    float z;
};

Quaternion identityQuat();

Quaternion operator *(Quaternion left, Quaternion right);

Quaternion inverse(Quaternion q);

Quaternion expToQuat(float angle, Vector3f axis);

Vector3f getAxis(Quaternion q);

float getAngle(Quaternion q);

float[16] getMatrix(Quaternion q);

