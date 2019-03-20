#include "Object.hpp"

Object::Object()
{
    vertices.push_back({0.5, 0.5, 0});
    vertices.push_back({0.5, -0.5, 0});
    vertices.push_back({-0.5, -0.5, 0});
    vertices.push_back({-0.5, 0.5, 0});
}

Object::Object(std::vector<Vec3> vertices)
{
    for(Vec3 v : vertices)
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
        glRotatef(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);
        glTranslatef(position.x, position.y, position.z);
        glColor3f(color.x, color.y, color.z);
        glBegin(GL_POLYGON);
        {
            for(Vec3 v : vertices)
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

void Object::setPosition(Vec3 v)
{
    position = v;
}

void Object::setRotation(float f, Vec3 v)
{
    rotationAxis = v;
    rotationAngle = f;
}

void Object::setScale(Vec3 v)
{
    scale = v;
}

void Object::setColor(Vec3 v)
{
    color = v;
}

void Object::addChild(std::unique_ptr<Object> obj)
{
    childs.push_back(std::move(obj));
}