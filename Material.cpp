#include "Material.hpp"

Material::Material()
{

}

Material::~Material()
{

}

void Material::applyMaterial()
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &shininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_COLOR_INDEXES, colorIndices);
}

void Material::setAmbient(Vector4f ambient)
{
    this->ambient[0] = ambient.x;
    this->ambient[1] = ambient.y;
    this->ambient[2] = ambient.z;
    this->ambient[3] = ambient.w;
}
void Material::setDiffuse(Vector4f diffuse)
{
    this->diffuse[0] = diffuse.x;
    this->diffuse[1] = diffuse.y;
    this->diffuse[2] = diffuse.z;
    this->diffuse[3] = diffuse.w;
}

void Material::setSpecular(Vector4f specular)
{
    this->specular[0] = specular.x;
    this->specular[1] = specular.y;
    this->specular[2] = specular.z;
    this->specular[3] = specular.w;
}

void Material::setEmission(Vector4f emission)
{
    this->emission[0] = emission.x;
    this->emission[1] = emission.y;
    this->emission[2] = emission.z;
    this->emission[3] = emission.w;
}

void Material::setShininess(float shininess)
{
    this->shininess = shininess;
}

void Material::setColorIndices(Vector3f colorIndices)
{
    this->colorIndices[0] = colorIndices.x;
    this->colorIndices[1] = colorIndices.y;
    this->colorIndices[2] = colorIndices.z;
}