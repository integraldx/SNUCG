#include "Model.hpp"

Model::Model(std::shared_ptr<Object> o)
{
    root = std::move(o);
}

Model::~Model()
{

}

void Model::draw()
{
    glPushMatrix();
    {
        glTranslatef(position.x, position.y, position.z);
        glRotatef(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);

        root->draw();

    }
    glPopMatrix();
}

void Model::setPosition(Vector3f v)
{
    position = v;
}

void Model::setRotation(float f, Vector3f v)
{
    rotationAxis = v;
    rotationAngle = f;
}

void Model::setScale(Vector3f v)
{
    scale = v;
}