#pragma once
#include <iostream>
#include <fstream>
#include "Model.hpp"
#include <memory>
#include <string>
#include <sstream>
#include "SplinedObject.hpp"
#include "Model.hpp"

class SplineParser
{
private:
    

public:
    static std::shared_ptr<Model> getModelFromTxt(std::string s);
};