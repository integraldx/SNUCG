#pragma once

struct Vector3f
{
    float x;
    float y;
    float z;
};

Vector3f operator * (float mul, Vector3f v);

Vector3f operator * (Vector3f v, float mul);

float dotProduct(Vector3f left, Vector3f right);

Vector3f crossProduct(Vector3f left, Vector3f right);

Vector3f operator + (Vector3f left, Vector3f right);

Vector3f operator - (Vector3f left, Vector3f right);
