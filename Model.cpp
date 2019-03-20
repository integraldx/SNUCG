#include "Model.hpp"

Model::Model(std::unique_ptr<Object> o)
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

void Model::setPosition(Vec3 v)
{
    position = v;
}

void Model::setRotation(float f, Vec3 v)
{
    rotationAxis = v;
    rotationAngle = f;
}

void Model::setScale(Vec3 v)
{
    scale = v;
}