#pragma once

#include <firal/common.h>

class Object {
public:
    Object();
    ~Object();

    // virtual void update(float dt) = 0;
    // virtual void render() = 0;

protected:
    // Object* parent; maybe later
    Vector3f position;
    Vector3f forward;
    Vector3f right;
    Vector3f up;
};
