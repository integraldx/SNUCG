#include "Util.hpp"

Vec3 normalizeVec3(Vec3 v)
{
    float scale = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
    Vec3 ret = {v.x / scale, v.y / scale, v.z / scale};

    return ret;
}

Vec3 operator + (Vec3 left, Vec3 right)
{
    return {left.x + right.x, left.y + right.y, left.z + right.z};
}

float innerProduct(Vec3 left, Vec3 right)
{
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

Vec3 crossProduct(Vec3 left, Vec3 right)
{
    Vec3 ret;
    ret.x = left.y * right.z - left.z * right.y;
    ret.y = -(left.x * right.z - left.z * right.x);
    ret.z = left.x * right.y - left.y * right.x;

    return ret;
}

Vec3 operator * (Vec3 v, float mul)
{
    v.x *= mul;
    v.y *= mul;
    v.z *= mul;

    return v;
}

Vec3 operator * (float mul, Vec3 v)
{
    v.x *= mul;
    v.y *= mul;
    v.z *= mul;

    return v;
}

Vec3 operator /(Vec3 v, float div)
{
    v.x /= div;
    v.y /= div;
    v.z /= div;

    return v;
}
