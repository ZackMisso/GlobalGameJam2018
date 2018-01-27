#pragma once

#include <firal/common.h>
#include <firal/object.h>
#include <firal/material.h>

class Tree : public Object {
public:
    Tree();

    virtual void update(float dt);
    virtual void render(Matrix4f vp, Matrix4f invV);

private:
    Material* leavesMaterial;
    Material* trunkMaterial;

    float trunkSize;
    float heightScale;
    int height;
};
