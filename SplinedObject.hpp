#pragma once
#include "Object.hpp"

class SplinedObject : public Object
{
private:
    int interpolationLevel;

    std::vector<Vector3f> generateSplinedVertices();
    

public:
    SplinedObject(std::vector<Vector3f> v);
    SplinedObject(std::vector<Vector3f> v, int interpolationLevel);
    void draw();
    
};