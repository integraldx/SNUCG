#include "SplinedObject.hpp"
SplinedObject::SplinedObject(std::vector<Vector3f> v)
: Object(v), interpolationLevel(1)
{

}

SplinedObject::SplinedObject(std::vector<Vector3f> v, int interpolationLevel)
: Object(v), interpolationLevel(interpolationLevel)
{

}

void SplinedObject::draw() 
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
            for(Vector3f v : generateSplinedVertices())
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
}

std::vector<Vector3f> SplinedObject::generateSplinedVertices()
{
    std::vector<Vector3f> result;
    for(int i = 0; i < vertices.size() - 1; i++)
    {
        Vector3f tangent1;
        Vector3f tangent2;
        if(i == 0)
        {
            tangent2 = (vertices[i + 2] - vertices[i]) * 0.5;
            tangent1 = (vertices[1] - tangent2 - vertices[0]);
        }
        else if(i == vertices.size() - 2)
        {
            tangent1 = (vertices[i + 1] - vertices[i - 1]) * 0.5;
            tangent2 = (vertices[i + 1] - (vertices[i] + tangent1));
        }
        else
        {
            tangent1 = (vertices[i + 1] - vertices[i - 1]) * 0.5;
            tangent2 = (vertices[i + 2] - vertices[i]) * 0.5;
        }
        
        

        Vector3f ctrlPoints[4];
        ctrlPoints[0] = vertices[i];
        ctrlPoints[1] = vertices[i] + tangent1;
        ctrlPoints[2] = vertices[i + 1] - tangent2;
        ctrlPoints[3] = vertices[i + 1];
        auto pFunc = [ctrlPoints](float t)
        {
            return pow((1 - t), 3) * ctrlPoints[0] +
            3 * pow((1 - t), 2) * pow(t, 1) * ctrlPoints[1] + 
            3 * pow((1 - t), 1) * pow(t, 2) * ctrlPoints[2] +
            pow(t, 3) * ctrlPoints[3];
        };
        for(int j = 0; j < interpolationLevel; j++)
        {
            result.push_back(pFunc((float)j / (interpolationLevel)));
        }
    }
    return result;
}