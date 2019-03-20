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

Mat4x4 vec3ToTranslation(Vec3 coords)
{
    Mat4x4 mat;

    mat.values[0][3] = coords.x;
    mat.values[1][3] = coords.y;
    mat.values[2][3] = coords.z;

    return mat;
}

Mat4x4 vec3ToRotation(Vec3 coords)
{
    Mat4x4 mat;

    mat.values[0][0] = cosf(coords.z) * cosf(coords.y);
    mat.values[0][1] = cosf(coords.z) * sinf(coords.y) * sinf(coords.x) - sinf(coords.z) * cosf(coords.x);
    mat.values[0][2] = cosf(coords.z) * sinf(coords.y) * cosf(coords.x) + sinf(coords.z) * sinf(coords.x);
    mat.values[1][0] = sinf(coords.z) * cosf(coords.y);
    mat.values[1][1] = sinf(coords.z) * sinf(coords.y) * sinf(coords.x) + cosf(coords.z) * cosf(coords.x);
    mat.values[1][2] = sinf(coords.z) * sinf(coords.y) * cosf(coords.x) - cosf(coords.z) * sinf(coords.x);
    mat.values[2][0] = -sinf(coords.y);
    mat.values[2][1] = cosf(coords.y) * sinf(coords.x);
    mat.values[2][2] = cosf(coords.y) * cosf(coords.x);

    return mat;
}

Mat4x4 vec3ToScale(Vec3 coords)
{
    Mat4x4 mat;

    mat.values[0][0] = coords.x;
    mat.values[1][1] = coords.y;
    mat.values[2][2] = coords.z;

    return mat;
}

