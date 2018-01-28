#include <firal/util.h>

Matrix4f scale(float x, float y, float z) {
    Matrix4f matrix;

    matrix(0, 0) = x;
    matrix(1, 1) = y;
    matrix(2, 2) = z;
    matrix(3, 3) = 1.f;

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (i != j) matrix(i, j) = 0.f;

    return matrix;
}

Matrix4f translate(float x, float y, float z) {
    Matrix4f matrix;

    matrix.col(0) << 1, 0, 0, 0;
    matrix.col(1) << 0, 1, 0, 0;
    matrix.col(2) << 0, 0, 1, 0;
    matrix.col(3) << x, y, z, 1;

    return matrix;
}

Matrix4f rotate(float a, float x, float y, float z) {
    Matrix4f matrix;

    float d = sqrt(x*x + y*y + z*z);
    float aa = PI / 180 * a;
    float xx = x / d;
    float yy = y / d;
    float zz = z / d;
    float c = cos(a);
    float s = sin(a);
    float t = 1 - c;

    matrix(0, 0) = xx * xx * t + c;
    matrix(0, 1) = xx * yy * t - zz * s;
    matrix(0, 2) = xx * zz * t + yy * s;
    matrix(0, 3) = 0;

    matrix(1, 0) = yy * xx * t + zz * s;
    matrix(1, 1) = yy * yy * t + c;
    matrix(1, 2) = yy * zz * t - xx * s;
    matrix(1, 3) = 0;

    matrix(2, 0) = zz * xx * t - yy * s;
    matrix(2, 1) = zz * yy * t + xx * s;
    matrix(2, 2) = zz * zz * t + c;
    matrix(2, 3) = 0;

    matrix(3, 0) = 0;
    matrix(3, 1) = 0;
    matrix(3, 2) = 0;
    matrix(3, 3) = 1;

    return matrix;
}

Matrix4f frustum(float l, float r, float b, float t, float n, float f) {
    Matrix4f matrix;

    matrix(0, 0) = 2 * n / (r - l);
    matrix(0, 1) = 0;
    matrix(0, 2) = (r + l) / (r - l);
    matrix(0, 3) = 0;

    matrix(1, 0) = 0;
    matrix(1, 1) = 2 * n / (t - b);
    matrix(1, 2) = (t + b) / (t - b);
    matrix(1, 3) = 0;

    matrix(2, 0) = 0;
    matrix(2, 1) = 0;
    matrix(2, 2) = -(f + n) / (f - n);
    matrix(2, 3) = -2 * f * n / (f - n);

    matrix(3, 0) = 0;
    matrix(3, 1) = 0;
    matrix(3, 2) = -1;
    matrix(3, 3) = 0;

    return matrix;
}

MatrixXf perspective(float fov, float aspect, float near, float far) {
    float y = tan(fov * PI / 360) * near;
    float x = y * aspect;
    return frustum(-x, x, -y, y, near, far);
}

void printMatrix(Matrix4f matrix) {
    for (int i = 0; i < matrix.rows(); i++) {
        for (int j = 0; j < matrix.cols(); j++) {
            cout << " " << matrix(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}
