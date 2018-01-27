#pragma once

#include <firal/common.h>

class Object {
public:
    Object();
    ~Object();

    // virtual void update(float dt, Input* input);
    virtual void update(float dt) = 0;
    virtual void render(Matrix4f vp, Matrix4f invV) = 0;

    void translateObject(float x, float y, float z);
    void rotateObject(float a, float x, float y, float z);

    void setPosition(Vector3f param) { position = param; }
    void setForward(Vector3f param) { forward = param; }
    void setRight(Vector3f param) { right = param; }
    void setUp(Vector3f param) { up = param; }

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
