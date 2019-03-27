#pragma once

#include "Model.hpp"
#include <memory>
#include <vector>
#include <math.h>

class Pod
{
private:
    std::shared_ptr<Model> podModel;
    std::vector<std::shared_ptr<Object>> legs;
public:
    Pod(std::shared_ptr<Model>);
    void setPosition(Vec3);
    void setRotation(float, Vec3);
    void setScale(Vec3);
    void rotateLeftThigh(float deltaAngle);
    void rotateLeftLeg(float deltaAngle);
    void rotateRightThigh(float deltaAngle);
    void rotateRightLeg(float deltaAngle);

    static std::shared_ptr<Pod> getPod();

    std::shared_ptr<Model> getModel();

};