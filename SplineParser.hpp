#pragma once
#include <iostream>
#include <fstream>
#include "Model.hpp"
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <functional>
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


    std::vector<SplineParser::CrossSection> crossSections;

    std::vector<SplineParser::CrossSection> getSplinedSections(int splineLevel);
    static std::vector<Vector3f> closedBSpline(std::vector<Vector3f> v, int splineLevel)
    {
        std::vector<Vector3f> result;
        for(int i = 0; i < v.size(); i++)
        {
            std::function<Vector3f(float)> func;
            Vector3f controlPoints[] = 
            {
                v[(i + v.size() - 1) % v.size()],
                v[(i + v.size()) % v.size()],
                v[(i + v.size() + 1) % v.size()],
                v[(i + v.size() + 2) % v.size()]
            };

            func = [controlPoints](float t)
            {
                return 
                Vector3f{
                    1 / 6.0 * pow(1 - t, 3) * controlPoints[0] +
                    1 / 6.0 * (3 * pow(t, 3) - 6 * pow(t, 2) + 4) * controlPoints[1] +
                    1 / 6.0 * (-3 * pow(t, 3) + 3 * pow(t, 2) + 3 * t + 1) * controlPoints[2] +
                    1 / 6.0 * pow(t, 3) * controlPoints[3] 
                };
            };

            for(int j = 0; j < splineLevel; j++)
            {
                result.push_back(func((float)j / splineLevel));
            }
        }
        return result;
    }
    static std::vector<Vector3f> closedCatMullSpline(std::vector<Vector3f> v, int splineLevel)
    {
        std::vector<Vector3f> result;
        for(int i = 0; i < v.size(); i++)
        {
            std::function<Vector3f(float)> func;
            Vector3f controlPoints[] = 
            {
                v[(i + v.size() - 1) % v.size()],
                v[(i + v.size()) % v.size()],
                v[(i + v.size() + 1) % v.size()],
                v[(i + v.size() + 2) % v.size()]
            };

            func = [controlPoints](float t)
            {
                Vector3f a[] = {
                    (-t) * controlPoints[0] + (t + 1) * controlPoints[1],
                    (1 - t) * controlPoints[1] + (t) * controlPoints[2],
                    (2 - t) * controlPoints[2] + (t - 1) * controlPoints[3]
                };
                Vector3f b[] = {
                    (1 - t) * 0.5 * a[0] + (t + 1) * 0.5 * a[1],
                    (2 - t) * 0.5 * a[1] + (t) * 0.5 * a[2]
                };
                return (1 - t) * b[0] + t * b[1];
            };

            for(int j = 0; j < splineLevel; j++)
            {
                result.push_back(func((float)j / splineLevel));
            }
        }
        return result;
    }
public:
    static SplineParser parseFile(std::string s);
    std::shared_ptr<Object> generateObject(int splineLevel);
};

std::vector<Vector3f> operator *(float left, std::vector<Vector3f> right);

std::vector<Vector3f> operator +(std::vector<Vector3f> left, std::vector<Vector3f> right);