#pragma once

#include <firal/common.h>
#include <nanogui/screen.h>

class Render {
public:
    static void initialize();

    static MatrixXu cube_inds;
    static MatrixXf cube_verts;
    static MatrixXf cube_norms;

    // static MatrixXu square_inds;
    // static MatrixXf square_verts;
    // static MatrixXf square_norms;
};
