#include "Camera.hpp"

void Camera::applyDeltaPosition(Vector3f v)
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

Vector3f Camera::getLookDirection()
{
    return lookDirection;
}

Vector3f Camera::getPosition()
{
    return position;
}

Vector3f Camera::getUp()
{
    return up;
}