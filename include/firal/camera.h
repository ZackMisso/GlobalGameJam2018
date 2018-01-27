#pragma once

#include <firal/common.h>
#include <firal/object.h>

class Camera : public Object {
public:
    Camera();
    ~Camera();

    void lookAt();
    Object* traceRay(float x, float y);
};
