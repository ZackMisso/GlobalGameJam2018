#pragma once

#include <firal/common.h>
#include <firal/object.h>

class Light : public Object {
public:
    Light();

    virtual void update(float dt);
    virtual void render(Matrix4f vp, Matrix4f invV);
};
