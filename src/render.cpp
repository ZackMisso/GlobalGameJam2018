#include <firal/render.h>

MatrixXu Render::cube_inds;
MatrixXf Render::cube_verts;
MatrixXf Render::cube_norms;

void Render::initialize() {
    // temp

    MatrixXu cube_inds(3, 2); /* Draw 2 triangles */
    cube_inds.col(0) << 0, 1, 2;
    cube_inds.col(1) << 2, 3, 0;

    MatrixXf cube_verts(3, 4);
    cube_verts.col(0) << -1, -1, 0;
    cube_verts.col(1) <<  1, -1, 0;
    cube_verts.col(2) <<  1,  1, 0;
    cube_verts.col(3) << -1,  1, 0;

    // // initialize cube verts
    // cube_verts = MatrixXf(3, 24);
    // cube_verts.col(0) << -1, -1,  1;
    // cube_verts.col(1) << 1, -1,  1;
    // cube_verts.col(2) << 1,  1,  1;
    // cube_verts.col(3) << 1,  1,  1;
    // cube_verts.col(4) << 1, -1, -1;
    // cube_verts.col(5) << 1,  1, -1;
    // cube_verts.col(6) << 1,  1, -1;
    // cube_verts.col(7) << 1, -1, -1;
    // cube_verts.col(8) << 1,  1, -1;
    // cube_verts.col(9) << 1,  1,  1;
    // cube_verts.col(10) << 1,  1,  1;
    // cube_verts.col(11) << 1,  1, -1;
    // cube_verts.col(12) << 1, -1, -1;
    // cube_verts.col(13) << 1, -1, -1;
    // cube_verts.col(14) << 1, -1,  1;
    // cube_verts.col(15) << 1, -1,  1;
    // cube_verts.col(16) << 1, -1, -1;
    // cube_verts.col(17) << 1,  1, -1;
    // cube_verts.col(18) << 1,  1,  1;
    // cube_verts.col(19) << 1, -1,  1;
    // cube_verts.col(20) << 1, -1, -1;
    // cube_verts.col(21) << 1, -1,  1;
    // cube_verts.col(22) << 1,  1,  1;
    // cube_verts.col(23) << 1,  1, -1;
    //
    // // initialize cube ind
    // cube_inds = MatrixXu(3, 24);
    // cube_inds.col(0) << 0, 0, 1;
    // cube_inds.col(1) << 0, 0, 1;
    // cube_inds.col(2) << 0, 0, 1;
    // cube_inds.col(3) << 0, 0, 1;
    // cube_inds.col(4) << 0, 0, -1;
    // cube_inds.col(5) << 0, 0, -1;
    // cube_inds.col(6) << 0, 0, -1;
    // cube_inds.col(7) << 0, 0, -1;
    // cube_inds.col(8) << 0, 1, 0;
    // cube_inds.col(9) << 0, 1, 0;
    // cube_inds.col(10) << 0, 1, 0;
    // cube_inds.col(11) << 0, 1, 0;
    // cube_inds.col(12) << 0, -1, 0;
    // cube_inds.col(13) << 0, -1, 0;
    // cube_inds.col(14) << 0, -1, 0;
    // cube_inds.col(15) << 0, -1, 0;
    // cube_inds.col(16) << 1, 0, 0;
    // cube_inds.col(17) << 1, 0, 0;
    // cube_inds.col(18) << 1, 0, 0;
    // cube_inds.col(19) << 1, 0, 0;
    // cube_inds.col(20) << -1, 0, 0;
    // cube_inds.col(21) << -1, 0, 0;
    // cube_inds.col(22) << -1, 0, 0;
    // cube_inds.col(23) << -1, 0, 0;
    //
    // // initialize cube norms
    // cube_verts = MatrixXf(3, 12);
    // cube_verts.col(0) << 0,  1,  2;
    // cube_verts.col(1) << 0,  2,  3;
    // cube_verts.col(2) << 4,  5,  6;
    // cube_verts.col(3) << 4,  6,  7;
    // cube_verts.col(4) << 8,  9, 10;
    // cube_verts.col(5) << 8, 10, 11;
    // cube_verts.col(6) << 2, 13, 14;
    // cube_verts.col(7) << 2, 14, 15;
    // cube_verts.col(8) << 6, 17, 18;
    // cube_verts.col(9) << 6, 18, 19;
    // cube_verts.col(10) << 0, 21, 22;
    // cube_verts.col(11) << 0, 22, 23;
}
