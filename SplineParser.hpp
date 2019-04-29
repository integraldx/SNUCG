#pragma once
#include <iostream>
#include <fstream>
#include "Model.hpp"
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include "SplinedObject.hpp"
#include "Model.hpp"

class SplineParser
{
private:
    enum SplineMode{BSPLINE, CATMULL_ROM} splineMode;
    int controlPointsNum;
    struct CrossSection
    {
        Vector3f position;
        Quaternion orientation;
        float scale;
        std::vector<Vector3f> surface;

        Vector3f getAppliedVertexAt(int index);
    };

    int interpolationLevel;

    std::vector<SplineParser::CrossSection> crossSections;

public:
    static SplineParser parseFile(std::string s);
    std::shared_ptr<Object> generateObject(int splineLevel);
    void setInterpolationLevel(int i);
};