#include <iostream>
#include <vector>
#include <string>

// for eigen
#include <nanogui/glutil.h>

#include <chrono>
using namespace std::chrono_literals;
using namespace std::chrono;
using namespace std;

using Eigen::Vector2i;
using Eigen::Vector2f;
using Eigen::Vector3i;
using Eigen::Vector3f;

using Eigen::Matrix3f;
using Eigen::Matrix4f;
// using Eigen::Matrix3u;
// using Eigen::Matrix4u;
using MatrixXu = Eigen::Matrix<uint32_t, Eigen::Dynamic, Eigen::Dynamic>;
using Eigen::MatrixXf;

using clockc = std::chrono::high_resolution_clock;

#define PI 3.14159265358979323846f
#define EPSILON 1e-8
#define SQRT_2 1.f // TODO
#define INV_SQRT_2 1.f // TODO
