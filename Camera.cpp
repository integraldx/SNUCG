#include "Camera.hpp"

Vector3f Camera::getPosition()
{
    Vector3f v =
    {
        (sin(viewAngleHorizontal) * cos(viewAngleVertical)),
        (sin(viewAngleVertical)),
        (cos(viewAngleHorizontal) * cos(viewAngleVertical))
    };

    return v * zoom;
}

Vector3f Camera::rotateViewplaneToVector(Vector3f v)
{
    Vector3f ret =
    {
        (v.x * cos(viewAngleHorizontal) - v.y * sin(viewAngleVertical) * sin(viewAngleHorizontal)),
        (v.y * cos(viewAngleVertical)),
        (v.x * -sin(viewAngleHorizontal) - v.y * sin(viewAngleVertical) * cos(viewAngleHorizontal))
    };

    return ret;
}

Vector3f Camera::getLookDirection()
{
    return normalize(-1 * getPosition());
}

Vector3f Camera::getUp()
{
    Vector3f v = 
    {
        (-sin(viewAngleHorizontal) * sin(viewAngleVertical)),
        (cos(viewAngleVertical)),
        (-cos(viewAngleHorizontal) * sin(viewAngleVertical))
    };

    return v;
}

float Camera::getFOV()
{
    return fov;
}

void Camera::applyDeltaFOV(float delta)
{
    fov += delta;
}

void Camera::rotateCameraHorizontally(float angle)
{
    viewAngleHorizontal += angle;

}

void Camera::rotateCameraVertically(float angle)
{
    if(cos(viewAngleVertical + angle) > 0)
    {
        viewAngleVertical += angle;
    }
}

void Camera::applyDeltaZoom(float deltaZoom)
{
    if(zoom + deltaZoom > 0)
    {
        zoom += deltaZoom;
    }
}