#pragma once
#include "Object.hpp"
#include "Camera.hpp"
#include "SceneManager.hpp"


class SortedObject : public Object
{
    private:
    std::vector<Face> faceVector;
    static bool faceSorter(Face left, Face right);

    public:
    SortedObject(std::vector<Vector3f> v);
    void draw();
    void sort();

};