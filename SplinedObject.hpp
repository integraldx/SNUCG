#pragma once
#include "Object.hpp"

class SplinedObject : public Object
{
private:
    int interpolationLevel;

    std::vector<Vector3f> generateSplinedVertices();
    std::vector<SplinedObject> generateSplinedObjects();
    

public:
    SplinedObject();
    SplinedObject(std::vector<Vector3f> v);
    SplinedObject(std::vector<Vector3f> v, int interpolationLevel);
    void draw();
    enum SplineKind{BSPLINE, CATMULL_ROM} splineKind;
};