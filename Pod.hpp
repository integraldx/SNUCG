#pragma once

#include "Model.hpp"
#include <memory>
#include <math.h>

class Pod
{
private:
    std::shared_ptr<Model> podModel;
public:
    Pod(std::shared_ptr<Model>);
    void rotateLeftFirst(Vec3 delta);

    static std::shared_ptr<Pod> getPod();

    std::shared_ptr<Model> getModel();

};