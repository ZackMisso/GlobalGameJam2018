#include <firal/object.h>

Object::Object() {
    position = Vector3f(0.f, 0.f, 0.f);
    forward = Vector3f(0.f, 0.f, 0.f);
    right = Vector3f(0.f, 0.f, 0.f);
    up = Vector3f(0.f, 0.f, 0.f);
}

Object::~Object() {
    // TODO
}
