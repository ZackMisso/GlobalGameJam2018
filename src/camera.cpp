#include <firal/camera.h>

Camera::Camera() {
    dirty = true;
}

Camera::~Camera() {
    input = 0x0;
}

Matrix4f Camera::lookAt(Object* other) {
    Matrix4f matrix;
    Matrix4f trans;
    Matrix4f orien;

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

    orien.col(0) << right[0], right[1], right[2], 0;
    orien.col(1) << up[0], up[1], up[2], 0;
    orien.col(2) << forward[0], forward[1], forward[2], 0;
    orien.col(3) << 0, 0, 0, 1;

    trans.col(0) << 1, 0, 0, 0;
    trans.col(1) << 0, 1, 0, 0;
    trans.col(2) << 0, 0, 1, 0;
    trans.col(3) << -position[0], -position[1], -position[2], 1;

    matrix = orien * trans;

    return matrix;
}

void Camera::update(float dt) {
    // if (input->getWKeyDown()) { cout << "W IS DOWN " << endl; }
    // if (input->getAKeyDown()) { cout << "A IS DOWN " << endl; }

    if (input->getWKeyDown()) {
        position = position + Vector3f(0.f, 0.f, dt);
        dirty = true;
    }

    if (input->getSKeyDown()) {
        position = position + Vector3f(0.f, 0.f, -dt);
        dirty = true;
    }
}

void Camera::render() {
    // will do nothing
}

Object* Camera::traceRay(float x, float y) {
    // TODO
    return 0x0;
}
