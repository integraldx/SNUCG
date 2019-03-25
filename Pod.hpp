#pragma once

#include "Model.hpp"
#include <memory>

class Pod : Model
{

public:

    static std::shared_ptr<Model> getPod();

};