#include "SplinedObject.hpp"
SplinedObject::SplinedObject(std::vector<Vector3f> v)
: Object(v), interpolationLevel(0)
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
    {
        Vector3f tangent1 = (vertices[1] - vertices[0]) * 0.5;
        Vector3f tangent2 = (vertices[2] - vertices[0]) * 0.5;
        Vector3f ctrlPoints[4];
        ctrlPoints[0] = vertices[0];
        ctrlPoints[1] = vertices[0] + tangent1;
        ctrlPoints[2] = vertices[1] - tangent2;
        ctrlPoints[3] = vertices[1];
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
    for(int i = 1; i < vertices.size() - 2; i++)
    {
        Vector3f tangent1 = (vertices[i + 1] - vertices[i - 1]) * 0.5;
        Vector3f tangent2 = (vertices[i + 2] - vertices[i]) * 0.5;
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
        for(int j = 0; j < interpolationLevel * 2; j++)
        {
            result.push_back(pFunc((float)j / (interpolationLevel * 2)));
        }
    }
    {
        int fin = vertices.size() - 1;
        Vector3f tangent1 = (vertices[fin] - vertices[fin - 2]) * 0.5;
        Vector3f tangent2 = (vertices[fin] - vertices[fin - 1]) * 0.5;
        Vector3f ctrlPoints[4];
        ctrlPoints[0] = vertices[fin - 1];
        ctrlPoints[1] = vertices[fin - 1] + tangent1;
        ctrlPoints[2] = vertices[fin] - tangent2;
        ctrlPoints[3] = vertices[fin];
        auto pFunc = [ctrlPoints](float t)
        {
            return pow((1 - t), 3) * ctrlPoints[0] +
            3 * pow((1 - t), 2) * pow(t, 1) * ctrlPoints[1] + 
            3 * pow((1 - t), 1) * pow(t, 2) * ctrlPoints[2] +
            pow(t, 3) * ctrlPoints[3];
        };
        for(int j = 0; j <= interpolationLevel; j++)
        {
            result.push_back(pFunc((float)j / (interpolationLevel)));
        }
    }
    return result;
}
