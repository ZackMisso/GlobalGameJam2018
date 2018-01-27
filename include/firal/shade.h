#pragma once

#include <firal/common.h>
#include <nanogui/glutil.h>

class Shade {
public:
    static void initialize();
    static void deinitialize();

    static nanogui::GLShader quadShader;
};
