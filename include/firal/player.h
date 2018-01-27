#pragma once

#include <firal/common.h>
#include <firal/object.h>

class Player : public Object {
public:
    Player();
    ~Player();

    virtual void update(float dt);
    virtual void render();
protected:
};
