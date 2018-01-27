#pragma once

#include <firal/common.h>
#include <firal/object.h>
#include <firal/input.h>

class Camera : public Object {
public:
    Camera();
    ~Camera();

    virtual void update(float dt);
    virtual void render();

    Matrix4f lookAt(Object* other);
    Object* traceRay(float x, float y);

    void setInput(Input* param) { input = param; }

protected:
    Input* input;
    bool dirty;
};
