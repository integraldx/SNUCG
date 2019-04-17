#include "Object.hpp"

Object::Object()
{
    vertices.push_back({0.5, 0.5, 0});
    vertices.push_back({0.5, -0.5, 0});
    vertices.push_back({-0.5, -0.5, 0});
    vertices.push_back({-0.5, 0.5, 0});
}

Object::Object(std::vector<Vector3f> vertices)
{
    for(Vector3f v : vertices)
    {
        this->vertices.push_back(v);
    }
}

Object::~Object()
{

}

void Object::draw()
{
    glPushMatrix();
    {
        glTranslatef(position.x, position.y, position.z);
        glScalef(scale.x, scale.y, scale.z);
        glTranslatef(rotationCenter.x, rotationCenter.y, rotationCenter.z);
        float rotationAngle = getAngle(rotation) / M_PI * 180;
        Vector3f rotationAxis = getAxis(rotation);
        glRotatef(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);
        glTranslatef(-rotationCenter.x, -rotationCenter.y, -rotationCenter.z);
        if(hasColor)
        {
            glColor3f(color.x, color.y, color.z);
        }
        glBegin(GL_POLYGON);
        {
            for(Vector3f v : vertices)
            {
                glVertex3f(v.x, v.y, v.z);
            }
        }
        glEnd();
        for(auto& o : childs)
        {
            o->draw();
        }
    }
    glPopMatrix();
    return;
}

void Object::setPosition(Vector3f v)
{
    position = v;
}

void Object::setRotationCenter(Vector3f v)
{
    rotationCenter = v;
}

void Object::setRotation(float f, Vector3f v)
{
    Quaternion q = expToQuat(f / 180 * M_PI, v);
    rotation = q;
}

void Object::setScale(Vector3f v)
{
    scale = v;
}

void Object::setColor(Vector3f v)
{
    hasColor = true;
    color = v;
}

void Object::addChild(std::shared_ptr<Object> obj)
{
    childs.push_back(std::move(obj));
}

float Object::getRotationAngle()
{
    return getAngle(rotation) / M_PI * 180;
}

Vector3f Object::getRotationAxis()
{
    return getAxis(rotation);
}