#pragma once

#include <firal/common.h>
#include <firal/object.h>

class Camera : public Object {
public:
    Camera();
    ~Camera();

    Matrix4f lookAt(Object* other);
    Object* traceRay(float x, float y);

protected:
    bool dirty;
};
