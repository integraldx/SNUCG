#include "Camera.hpp"

void Camera::applyDeltaPosition(Vector3f v)
{
    position.x += v.x;
    position.y += v.y;
    position.z += v.z;
}

void Camera::rotateLookDirectionHorizontally(float angle)
{
    viewAngleHorizontal += angle * M_PI / 180;

    lookDirection.x = sin(viewAngleHorizontal) * cos(viewAngleVertical);
    lookDirection.z = cos(viewAngleHorizontal) * cos(viewAngleVertical);
}

void Camera::rotateLookDirectionVertically(float angle)
{
    viewAngleVertical += angle * M_PI / 180;

    lookDirection.x = sin(viewAngleHorizontal) * cos(viewAngleVertical);
    lookDirection.z = cos(viewAngleHorizontal) * cos(viewAngleVertical);
    lookDirection.y = sin(viewAngleVertical);
}

Vector3f Camera::getLookDirection()
{
    lookDirection.x = sin(viewAngleHorizontal) * cos(viewAngleVertical);
    lookDirection.z = cos(viewAngleHorizontal) * cos(viewAngleVertical);
    lookDirection.y = sin(viewAngleVertical);
    return lookDirection;
}


Vector3f Camera::getPosition()
{
    return position;
}

Vector3f Camera::getUp()
{
    up = {sin(viewAngleHorizontal) * sin(viewAngleVertical), cos(viewAngleVertical), cos(viewAngleHorizontal) * sin(viewAngleVertical)};
    return up;
}

float Camera::getFOV()
{
    return fov;
}

void Camera::applyDeltaFOV(float delta)
{
    fov += delta;
}