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

Quaternion affine(Quaternion left, Quaternion right);

Quaternion operator *(Quaternion left, Quaternion right);

Quaternion operator *(Quaternion left, float right);

Quaternion inverse(Quaternion q);

Quaternion expToQuat(float angle, Vector3f axis);

Vector3f getAxis(Quaternion q);

float getAngle(Quaternion q);

Quaternion normalize(Quaternion q);


