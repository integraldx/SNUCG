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
