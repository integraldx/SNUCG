#pragma once

#include "Model.hpp"
#include <memory>
#include <math.h>

class Pod
{
private:
    std::shared_ptr<Model> podModel;
    std::shared_ptr<Object> leftThigh;
    std::shared_ptr<Object> rightThigh;
    std::shared_ptr<Object> leftLeg;
    std::shared_ptr<Object> rightLeg;
public:
    Pod(std::shared_ptr<Model>);
    void rotateLeftThigh(float deltaAngle);
    void rotateLeftLeg(float deltaAngle);
    void rotateRightThigh(float deltaAngle);
    void rotateRightLeg(float deltaAngle);

    static std::shared_ptr<Pod> getPod();

    std::shared_ptr<Model> getModel();

};