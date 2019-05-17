#include "Object.hpp"

Object::Object()
{
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
        
        m.applyMaterial();
        for(int i = 0; i < vertices.size() - 2; i += 3)
        {
            auto normal = normalize(crossProduct(vertices[i + 1] - vertices[i], vertices[i + 2] - vertices[i]));
            glNormal3f(normal.x, normal.y, normal.z);
            glBegin(GL_POLYGON);
            {
                // m.applyMaterial();
                glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
                glVertex3f(vertices[i + 1].x, vertices[i + 1].y, vertices[i + 1].z);
                glVertex3f(vertices[i + 2].x, vertices[i + 2].y, vertices[i + 2].z);
            }
            glEnd();
        }
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

void Object::setRotation(Quaternion q)
{
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

void Object::setMaterial(Material m)
{
    this->m = m;
}
