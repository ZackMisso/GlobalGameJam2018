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

// MatrixXu cube_ind;
// MatrixXf cube_verts;
// MatrixXf cube_norms;

// float cube_verts[] = {
//     -1, -1,  1,
//      1, -1,  1,
//      1,  1,  1,
//     -1,  1,  1,
//     -1, -1, -1,
//     -1,  1, -1,
//      1,  1, -1,
//      1, -1, -1,
//     -1,  1, -1,
//     -1,  1,  1,
//      1,  1,  1,
//      1,  1, -1,
//     -1, -1, -1,
//      1, -1, -1,
//      1, -1,  1,
//     -1, -1,  1,
//      1, -1, -1,
//      1,  1, -1,
//      1,  1,  1,
//      1, -1,  1,
//     -1, -1, -1,
//     -1, -1,  1,
//     -1,  1,  1,
//     -1,  1, -1,
// };
//
// float cube_norms[] = {
//     0, 0, 1,
//     0, 0, 1,
//     0, 0, 1,
//     0, 0, 1,
//     0, 0, -1,
//     0, 0, -1,
//     0, 0, -1,
//     0, 0, -1,
//     0, 1, 0,
//     0, 1, 0,
//     0, 1, 0,
//     0, 1, 0,
//     0, -1, 0,
//     0, -1, 0,
//     0, -1, 0,
//     0, -1, 0,
//     1, 0, 0,
//     1, 0, 0,
//     1, 0, 0,
//     1, 0, 0,
//     -1, 0, 0,
//     -1, 0, 0,
//     -1, 0, 0,
//     -1, 0, 0,
// };
//
// float cube_ind[] = {
//     0,  1,  2,  0,  2,  3,
//     4,  5,  6,  4,  6,  7,
//     8,  9, 10,  8, 10, 11,
//    12, 13, 14, 12, 14, 15,
//    16, 17, 18, 16, 18, 19,
//    20, 21, 22, 20, 22, 23,
// };
