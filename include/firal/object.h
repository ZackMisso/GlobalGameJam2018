#pragma once

#include <firal/common.h>

class Object {
public:
    Object();
    ~Object();

    virtual void update(float dt) = 0;
    virtual void render() = 0;

    void translateObject(float x, float y, float z);
    void rotateObject(float a, float x, float y, float z);

    Vector3f getPosition() { return position; }
    Vector3f getForward() { return forward; }
    Vector3f getRight() { return right; }
    Vector3f getUp() { return up; }

protected:
    // Object* parent; maybe later
    Vector3f position;
    Vector3f forward;
    Vector3f right;
    Vector3f up;
};
