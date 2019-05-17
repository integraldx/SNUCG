#include "SortedObject.hpp"

SortedObject::SortedObject(std::vector<Vector3f> v)
{
    for (int i = 0; i < v.size(); i += 3)
    {
        faceVector.push_back({v[i], v[i + 1], v[i + 2], crossProduct(v[i + 1] - v[i], v[i + 2] - v[i])});
    }
}

void SortedObject::draw()
{
    sort();
    glPushMatrix();
    {
        glTranslatef(position.x, position.y, position.z);
        glTranslatef(rotationCenter.x, rotationCenter.y, rotationCenter.z);
        float rotationAngle = getAngle(rotation) / M_PI * 180;
        Vector3f rotationAxis = getAxis(rotation);
        glRotatef(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);
        glTranslatef(-rotationCenter.x, -rotationCenter.y, -rotationCenter.z);
        glScalef(scale.x, scale.y, scale.z);

        m.applyMaterial();

        for(auto a : faceVector)
        {
            glBegin(GL_POLYGON);
            glNormal3f(a.normal.x, a.normal.y, a.normal.z);
            glVertex3f(a.first.x, a.first.y, a.first.z);
            glVertex3f(a.second.x, a.second.y, a.second.z);
            glVertex3f(a.third.x, a.third.y, a.third.z);
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

void SortedObject::sort()
{
    std::sort(faceVector.begin(), faceVector.end(), faceSorter);
    return;
}

void SortedObject::setMaterial(Material m)
{
    this->m = m;
}

bool SortedObject::faceSorter(Face left, Face right)
{
    Vector3f leftAverage = (left.first + left.second + left.third) * (1.0f / 3);
    Vector3f rightAverage = (right.first + right.second + right.third) * (1.0f / 3);

    Vector3f leftDelta = leftAverage - SceneManager::cam.getCenter();
    Vector3f rightDelta = rightAverage - SceneManager::cam.getCenter();

    if(dotProduct(leftDelta, SceneManager::cam.getLookDirection()) < dotProduct(rightDelta, SceneManager::cam.getLookDirection()))
    {
        return false;
    }
    else
    {
        return true;
    }
}