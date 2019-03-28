#include "Camera.hpp"

void Camera::applyDeltaPosition(Vec3 v)
{
    position.x += v.x;
    position.y += v.y;
    position.z += v.z;
}

void Camera::rotateLookDirection(float angle)
{
    viewAngle += angle * M_PI / 180;

    lookDirection.x = sin(viewAngle);
    lookDirection.z = cos(viewAngle);

}

Vec3 Camera::getLookDirection()
{
    return lookDirection;
}

Vec3 Camera::getPosition()
{
    return position;
}

Vec3 Camera::getUp()
{
    return up;
}