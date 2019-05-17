#pragma once
#include <math.h>

struct Vector3f
{
    float x;
    float y;
    float z;
};

struct Vector4f
{
    float x;
    float y;
    float z;
    float w;
};

struct Face
{
    Vector3f first;
    Vector3f second;
    Vector3f third;
    Vector3f normal;
};

Vector3f operator * (float mul, Vector3f v);

Vector3f operator * (Vector3f v, float mul);

float dotProduct(Vector3f left, Vector3f right);

Vector3f crossProduct(Vector3f left, Vector3f right);

Vector3f operator + (Vector3f left, Vector3f right);

Vector3f operator - (Vector3f left, Vector3f right);

float getScale(Vector3f v);

Vector3f normalize(Vector3f v);

Vector4f operator * (float mul, Vector4f v);

Vector4f operator * (Vector4f v, float mul);

float dotProduct(Vector4f left, Vector4f right);

Vector4f crossProduct(Vector4f left, Vector4f right);

Vector4f operator + (Vector4f left, Vector4f right);

Vector4f operator - (Vector4f left, Vector4f right);

float getScale(Vector4f v);

Vector4f normalize(Vector4f v);