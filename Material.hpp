#pragma once
#include "Vectorf.hpp"
#include "Quaternion.hpp"
#include <GL/gl.h>

class Material 
{
    public:
    enum FaceMode{
        FRONTFACE,
        BACKFACE,
        FRONTBACKFACE
    };
        
    private:
    FaceMode faceMode = FRONTBACKFACE;
    GLfloat ambient[4] = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse[4] = {0.8, 0.8, 0.8, 1.0};
    GLfloat specular[4] = {0, 0, 0, 1};
    GLfloat emission[4] = {0, 0, 0, 1};
    float shininess = 0;
    GLfloat colorIndices[3] = {0, 1, 1};

    public:
    Material();
    ~Material();
    void applyMaterial();
    void setAmbient(Vector4f ambient);
    void setDiffuse(Vector4f diffuse);
    void setSpecular(Vector4f specular);
    void setEmission(Vector4f emission);
    void setShininess(float shininess);
    void setColorIndices(Vector3f colorIndices);

};