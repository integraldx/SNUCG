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
        Vector3f axis = getAxis(rotation);
        glRotatef(getAngle(rotation) * 360 / M_PI, axis.x, axis.y, axis.z);
        glTranslatef(position.x, position.y, position.z);

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
    rotation = expToQuat(f, v);
}

void Model::applyDeltaRotation(Quaternion q)
{
	
    Quaternion resultRotation = q * rotation;
	if(!(isnan(resultRotation.w) || isnan(resultRotation.x) || isnan(resultRotation.y) || isnan(resultRotation.z)))
	{
		rotation = resultRotation;
	}
}

void Model::setScale(Vector3f v)
{
    scale = v;
}
