#include "Object.hpp"

void Object::draw()
{
    glColor3f(color.x, color.y, color.z);
    glBegin(GL_POLYGON);
    {
        for(Vec3 v : vertices)
        {
            glVertex3f(v.x, v.y, v.z);
        }
    }
}