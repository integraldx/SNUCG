#include "Camera.hpp"

void Camera::applyDeltaZoom(float deltaZoom)
{
    if(zoom + deltaZoom > 0)
    {
        zoom += deltaZoom;
    }
}

void Camera::setZoom(float f)
{
    zoom = f;
}

Vector3f Camera::rotateViewplaneToVector(Vector3f v)
{
    Quaternion q = orientation * Quaternion{0, v.x, v.y, v.z} * inverse(orientation);
    return {q.x, q.y, q.z};
}

Vector3f Camera::getPosition()
{
    Quaternion q = orientation * Quaternion{0, 0, 0, 1} * inverse(orientation);
    return zoom * Vector3f{q.x, q.y, q.z};
}

void Camera::applyDeltaRotation(Quaternion q)
{
    orientation = q * orientation;
}


Vector3f Camera::getLookDirection()
{
    return normalize(-1 * getPosition());
}

void Camera::setRotation(Quaternion q)
{
    orientation = q;
}
Vector3f Camera::getUp()
{
    Quaternion q = orientation * Quaternion{0, 0, 1, 0} * inverse(orientation);
    return Vector3f{q.x, q.y, q.z};
}


float Camera::getFOV()
{
    return fov;
}

void Camera::setFOV(float f)
{
    fov = f;
}

void Camera::applyDeltaFOV(float delta)
{
    fov += delta;
}
