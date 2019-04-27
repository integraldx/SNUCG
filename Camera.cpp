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
    return zoom * (Vector3f{q.x, q.y, q.z}) + center;

    // return zoom * Vector3f{q.x, q.y, q.z};
}

void Camera::applyDeltaRotation(Quaternion q)
{
    Quaternion tempOrientation = q * orientation;
    Quaternion qua = tempOrientation * Quaternion{0, 0, 0, 1} * inverse(tempOrientation);
	if(~(isnan(qua.w) || isnan(qua.x) || isnan(qua.y) || isnan(qua.z)))
	{
		orientation = tempOrientation;
	}
}


Vector3f Camera::getLookDirection()
{
    Quaternion q = orientation * Quaternion{0, 0, 0, -1} * inverse(orientation);
    return {q.x, q.y, q.z};
}

void Camera::setRotation(Quaternion q)
{
    orientation = q;
}

void Camera::applyDeltaRotationByAngle(float horizontal, float vertical)
{
    Quaternion hDelta = expToQuat(horizontal, getUp());
    Quaternion vDelta = expToQuat(vertical, crossProduct(getUp(), getLookDirection()));

    orientation = hDelta * vDelta * orientation;
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

void Camera::applyDeltaPan(float x, float y)
{
    center = center +  x * normalize(crossProduct(this->getLookDirection(), this->getUp())) + (y * this->getUp());
}

void Camera::setCenter(Vector3f v)
{
    center = v;
}

Vector3f Camera::getCenter()
{
    return center;
}
