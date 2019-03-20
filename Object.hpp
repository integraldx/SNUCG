#pragma once

#include <vector>
#include "Util.hpp"
#include <gl/GL.h>
#include <gl/GLU.h>

class Object
{
private:
    std::vector<Vec3> vertices;
    Vec3 color;

public:
    void draw();

    

}