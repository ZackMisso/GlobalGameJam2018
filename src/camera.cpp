#include <firal/camera.h>

Camera::Camera() {
    dirty = true;
}

Camera::~Camera() {
    // TODO
}

Matrix4f Camera::lookAt(Object* other) {
    Matrix4f matrix;

    if (dirty) {
        Vector3f u = Vector3f(0.f, 1.f, 0.f);
        Vector3f f = position - other->getPosition();
        f.normalize();

        Vector3f r = u.cross(f);
        u = f.cross(r);

        right = r;
        up = u;
        forward = f;

        dirty = false;

        // r, u, f
    }

    matrix.col(0) << right[0], right[1], right[2], 0;
    matrix.col(1) << up[0], up[1], up[2], 0;
    matrix.col(2) << forward[0], forward[1], forward[2], 0;
    matrix.col(3) << 0, 0, 0, 1;

    return matrix;
}

Object* Camera::traceRay(float x, float y) {
    // TODO
    return 0x0;
}
