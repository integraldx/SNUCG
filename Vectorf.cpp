#include "Vectorf.hpp"

Vector3f operator * (float mul, Vector3f v)
{
    return {v.x * mul, v.y * mul, v.z * mul};
}

Vector3f operator * (Vector3f v, float mul)
{
    return mul * v;
}

float dotProduct(Vector3f left, Vector3f right)
{
    return (left.x * right.x + left.y * right.y + left.z * right.z);
}

Vector3f crossProduct(Vector3f left, Vector3f right)
{
    Vector3f result;
    result.x = left.y * right.z - left.z * right.y;
    result.y = left.z * right.x - left.x * right.z;
    result.z = left.x * right.y - left.y * right.x;

    return result;
}

Vector3f operator + (Vector3f left, Vector3f right)
{
    return {left.x + right.x, left.y + right.y, left.z + right.z};
}

Vector3f operator - (Vector3f left, Vector3f right)
{
    return {left.x - right.x, left.y - right.y, left.z - right.z};
}

float getScale(Vector3f v)
{
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

Vector3f normalize(Vector3f v)
{
    return v * (1 / getScale(v));
}

Vector4f operator * (float mul, Vector4f v)
{
    return {mul * v.x, mul * v.y, mul * v.z, mul * v.w};
}

Vector4f operator * (Vector4f v, float mul)
{
    return mul * v;
}

float dotProduct(Vector4f left, Vector4f right)
{
    return left.x * right.x + left.y * right.y + left.z * right.z + left.w * right.w;
}

Vector4f operator + (Vector4f left, Vector4f right)
{
    return {left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w};
}

Vector4f operator - (Vector4f left, Vector4f right)
{
    return {left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w};
}

float getScale(Vector4f v)
{
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.w, 2));
}

Vector4f normalize(Vector4f v)
{
    float scale = getScale(v);
    return {v.x / scale, v.y / scale, v.z / scale, v.w / scale};
}