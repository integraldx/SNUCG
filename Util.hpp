#pragma once

#include <math.h>

struct Vec3
{
    float x;
    float y;
    float z;
};

struct Mat4x4
{
    float values[4][4] =
    {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
};

Vec3 normalizeVec3(Vec3 v);

Vec3 crossProduct(Vec3 left, Vec3 right);

Vec3 operator + (Vec3 v, float add);

Vec3 operator - (Vec3 v, float sub);

Vec3 operator * (Vec3 v, float mul);

Vec3 operator / (Vec3 v, float div);