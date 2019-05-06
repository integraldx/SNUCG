#include "Quaternion.hpp"

Quaternion identityQuat()
{
    return {1, 0, 0, 0};
}

Quaternion operator *(Quaternion left, Quaternion right)
{
    float w = left.w * right.w - dotProduct(Vector3f{left.x, left.y, left.z}, Vector3f{right.x, right.y, right.z});
    Vector3f v = 
        left.w * (Vector3f){right.x, right.y, right.z} 
        + right.w * (Vector3f){left.x, left.y, left.z}
        + crossProduct(Vector3f{left.x, left.y, left.z}, Vector3f{right.x, right.y, right.z});
    
    return {w, v.x, v.y, v.z};
}

Quaternion expToQuat(float angle, Vector3f axis)
{
    float w = cos(angle / 2);
    Vector3f v = sin(angle / 2) * axis;
    return {w, v.x, v.y, v.z};
}


Quaternion inverse(Quaternion q)
{
    return {q.w, -q.x, -q.y, -q.z};
}

Vector3f getAxis(Quaternion q)
{
    float angle = getAngle(q) / 2;
    Vector3f v;
    v.x = q.x / sin(angle);
    v.y = q.y / sin(angle);
    v.z = q.z / sin(angle);

    return normalize(v);
}

float getAngle(Quaternion q)
{
    return acos(q.w) * 2;
}

Quaternion normalize(Quaternion q)
{
    float size = sqrt(pow(q.w, 2) + pow(q.x, 2) + pow(q.y, 2) + pow(q.z, 2));
    return {q.w / size, q.x / size, q.y / size, q.z / size};
}

Quaternion operator *(Quaternion left, float right)
{
    return {left.w * right, left.x * right, left.y * right, left.z * right};
}

Quaternion operator *(float left, Quaternion right)
{
    return right * left;
}

Quaternion operator +(Quaternion left, Quaternion right)
{
    return {left.w + right.w, left.x + right.x, left.y + right.y, left.z + right.z};
}

Quaternion affine (Quaternion left, Quaternion right)
{
    return {left.w / 2 + right.w / 2, left.x / 2 + right.x / 2 + left.y / 2 + right.y / 2, left.z / 2 + right.z / 2};
}

Quaternion pow (Quaternion q, float exp)
{
    return expToQuat(getAngle(q) * exp, getAxis(q));
}

Quaternion slerp (Quaternion q1, Quaternion q2, float t)
{
    float angle = acos(q1.w * q2.w + q1.x * q2.x + q1.y * q2.y + q1.z * q2.z);

    auto result = normalize(sin((1 - t) * angle) / sin(angle) * q1 + sin(t * angle) / sin(angle) * q2);
    if(isnan(result.w) || isnan(result.x) || isnan(result.y) || isnan(result.z))
    {
        return normalize((1 - t) * q1 + t * q2);
    }
    else
    {
        return result;
    }
} 