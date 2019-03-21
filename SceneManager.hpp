#pragma once

#include <vector>
#include <memory>
#include "Model.hpp"

class SceneManager
{
private:
    static std::vector<std::shared_ptr<Model>> toRender;

public:
    static void addRenderModel(std::shared_ptr<Model>);
    static void displayCallback();
};