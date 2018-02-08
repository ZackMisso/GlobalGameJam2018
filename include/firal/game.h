#pragma once

#include <firal/common.h>
#include <firal/subscreen.h>
#include <firal/player.h>
#include <firal/camera.h>
#include <firal/input.h>
#include <firal/tree.h>
#include <firal/map.h>
#include <nanogui/window.h>

class Game : public nanogui::Screen {
public:
    Game();
    ~Game();

    void initializeGUI();
    void initializeWorld();

    virtual bool keyboardEvent(int key, int scancode, int action, int modifiers);
    virtual bool mouseButtonEvent(const Vector2i &p, int button, bool down, int modifiers);

    virtual void draw(NVGcontext *ctx);
    virtual void drawContents();

    void update(float dt);
protected:
    nanogui::Window* gameWindow;
    clockc::time_point startTime;
    clockc::time_point currentTime;

    Player* player;
    Camera* camera;
    Input* input;
    Tree* test;
    Map* map;

    float aspect;
};
