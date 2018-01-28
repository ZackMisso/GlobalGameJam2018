#pragma once

#include <firal/common.h>

Matrix4f scale(float x, float y, float z);

Matrix4f translate(float x, float y, float z);

Matrix4f rotate(float a, float x, float y, float z);

Matrix4f frustum(float l, float r, float b, float t, float n, float f);

MatrixXf perspective(float fov, float aspect, float near, float far);
