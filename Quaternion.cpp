#include "Quaternion.hpp"

Quaternion identityQuat()
{
    return {1, 0, 0, 0};
}

Quaternion operator *(Quaternion left, Quaternion right)
{
    float w = left.w * right.w - dotProduct({left.x, left.y, left.z}, {right.x, right.y, right.z});
    Vector3f v = 
        left.w * (Vector3f){right.x, right.y, right.z} 
        + right.w * (Vector3f){left.x, left.y, left.z}
        + crossProduct({left.x, left.y, left.z}, {right.x, right.y, right.z});
    
    return {w, v.x, v.y, v.z};
}

Quaternion expToQuat(float angle, Vector3f axis)
{
    float w = cos(angle);
    Vector3f v = sin(angle) * axis;
    return {w, v.x, v.y, v.z};
}


Quaternion inverse(Quaternion q)
{
    return {q.w, -q.x, -q.y, -q.z};
}

Vector3f getAxis(Quaternion q)
{
    float angle = getAngle(q);
    Vector3f v;
    v.x = q.x / sin(angle);
    v.y = q.y / sin(angle);
    v.z = q.z / sin(angle);

    return normalize(v);
}

float getAngle(Quaternion q)
{
    return acos(q.w);
}
