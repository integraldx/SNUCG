#include "SphereObject.hpp"

void SphereObject::draw()
{
    glPushMatrix();
    {
        glTranslatef(position.x, position.y, position.z);
        glTranslatef(rotationCenter.x, rotationCenter.y, rotationCenter.z);
        float rotationAngle = getAngle(rotation) / M_PI * 180;
        Vector3f rotationAxis = getAxis(rotation);
        glRotatef(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);
        glTranslatef(-rotationCenter.x, -rotationCenter.y, -rotationCenter.z);

        m.applyMaterial();

        glutSolidSphere(scale.y, 50, 50);

        
        for(auto& o : childs)
        {
            o->draw();
        }
    }
    glPopMatrix();
    return;
}

void SphereObject::setPosition(Vector3f v)
{
    Object::setPosition(v);
}

void SphereObject::setScale(float f)
{
    Object::setScale({f, f, f});
}