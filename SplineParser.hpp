#pragma once
#include <iostream>
#include <fstream>
#include "Model.hpp"
#include <memory>
#include <string>

class SplineParser
{
private:
    

public:
    static std::shared_ptr<Model> getModelFromTxt(std::string s);
};