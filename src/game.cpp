#include <firal/game.h>
#include <firal/shade.h>
#include <firal/render.h>
#include <firal/util.h>

Game::Game() : nanogui::Screen(Eigen::Vector2i(800, 800), "Feigns Tale") {
    initializeGUI();
    initializeWorld();
}

Game::~Game() {
    delete player;
    delete camera;
    delete input;
}


void Game::initializeGUI() {
    // TODO

    performLayout();
}

void Game::initializeWorld() {
    Shade::initialize();
    Render::initialize();

    input = new Input();

    player = new Player();
    camera = new Camera();

    camera->setInput(input);
    camera->setPosition(Vector3f(0.f, 0.f, -5.f));

    player->setPosition(Vector3f(0.f, 0.f, 0.f));

    aspect = 1.f;

    // TODO
}


bool Game::keyboardEvent(int key, int scancode, int action, int modifiers) {
    if (key == GLFW_KEY_W) {
        if (action == GLFW_PRESS) { input->setWKey(true); return true; }
        else if (action == GLFW_RELEASE) { input->setWKey(false); return true; }
    }

    else if (key == GLFW_KEY_A) {
        if (action == GLFW_PRESS) { input->setAKey(true); return true; }
        else if (action == GLFW_RELEASE) { input->setAKey(false); return true; }
    }

    else if (key == GLFW_KEY_S) {
        if (action == GLFW_PRESS) { input->setSKey(true); return true; }
        else if (action == GLFW_RELEASE) { input->setSKey(false); return true; }
    }

    else if (key == GLFW_KEY_D) {
        if (action == GLFW_PRESS) { input->setDKey(true); return true; }
        else if (action == GLFW_RELEASE) { input->setDKey(false); return true; }
    }

    else if (key == GLFW_KEY_RIGHT) {
        if (action == GLFW_PRESS) { input->setRArrowKey(true); return true; }
        else if (action == GLFW_RELEASE) { input->setRArrowKey(false); return true; }
    }

    else if (key == GLFW_KEY_LEFT) {
        if (action == GLFW_PRESS) { input->setLArrowKey(true); return true; }
        else if (action == GLFW_RELEASE) { input->setLArrowKey(false); return true; }
    }

    else if (key == GLFW_KEY_UP) {
        if (action == GLFW_PRESS) { input->setUArrowKey(true); return true; }
        else if (action == GLFW_RELEASE) { input->setUArrowKey(false); return true; }
    }

    else if (key == GLFW_KEY_DOWN) {
        if (action == GLFW_PRESS) { input->setDArrowKey(true); return true; }
        else if (action == GLFW_RELEASE) { input->setDArrowKey(false); return true; }
    }

    else if (key == GLFW_KEY_1) {
        if (action == GLFW_PRESS) { input->setOneKey(true); return true; }
        else if (action == GLFW_RELEASE) { input->setOneKey(false); return true; }
    }

    else if (key == GLFW_KEY_2) {
        if (action == GLFW_PRESS) { input->setTwoKey(true); return true; }
        else if (action == GLFW_RELEASE) { input->setTwoKey(false); return true; }
    }

    else if (key == GLFW_KEY_3) {
        if (action == GLFW_PRESS) { input->setThreeKey(true); return true; }
        else if (action == GLFW_RELEASE) { input->setThreeKey(false); return true; }
    }

    return false;
}

bool Game::mouseButtonEvent(const Vector2i &p, int button, bool down, int modifiers) {
    // TODO
    return false;
}

// bool Game::mouseDragEvent(const Vector2i &p, const Vector2i &rel, int button, int modifiers) {
//     // TODO
//     return false;
// }
//
// bool Game::scrollEvent(const Vector2i &p, const Vector2f &rel) {
//     // TODO
//     return false;
// }

// TODO - maybe modify nanogui to allow for different update and draw loops
void Game::draw(NVGcontext *ctx) {
    // clearScreen(ctx);

    // clockc::time_point currentTime = high_resolution_clock::now();
    // duration<double> time_span = duration_cast<duration<double>>(currentTime - startTime);
    //
    // update(time_span.count());

    // cout << "DRAW ONE" << endl;

    // update stuffs
    // update()

    // draw screen overlay and objects

    // finish update loops
    startTime = currentTime;
    Screen::draw(ctx);
}

void Game::drawContents() {
    // main loop
    // cout << "DRAWING" << endl;
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    currentTime = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(currentTime - startTime);

    float dt = time_span.count();

    update(dt);

    Matrix4f mvp;
    mvp.setIdentity();

    Matrix4f model = rotate(glfwGetTime(), 1, 1, 1) * scale(0.25f, 0.25f, 0.25f);
    Matrix4f view = camera->lookAt(player);
    Matrix4f proj = perspective(120.f, aspect, 0.2f, 100.f);

    // if (input->getWKeyDown()) { cout << "W IS DOWN " << endl; }
    // if (input->getAKeyDown()) { cout << "A IS DOWN " << endl; }
    // cout << "DT: " << dt << endl;

    // printMatrix(view);

    mvp = proj * view * model;
    // mvp = view * model;
    // mvp = model;

    // Matrix3f zrot = Matrix3f(Eigen::AngleAxisf((float) glfwGetTime(),  Vector3f::UnitZ())) * 0.25f;
    // Matrix3f yrot = Matrix3f(Eigen::AngleAxisf((float) glfwGetTime(),  Vector3f::UnitY())) * 0.25f;
    // mvp.topLeftCorner<3,3>() = zrot * yrot;

    // mvp = rotate(glfwGetTime(), 1, 1, 1) * scale(0.25f, 0.25f, 0.25f);

    // mvp.row(0) *= (float) mSize.y() / (float) mSize.x();


    // mvp *= 40.f;
    // mvp.topLeftCorner<3,3>() = Matrix3f(Eigen::AngleAxisf(time_span.count(),  Vector3f::UnitZ())) * 0.25f;
    // mvp.row(0) *= (float) mSize.y() / (float) mSize.x();
    // cout << mSize.y() << endl;

    // MatrixXu indices(3, 2); /* Draw 2 triangles */
    // indices.col(0) << 0, 1, 2;
    // indices.col(1) << 2, 3, 0;
    //
    // MatrixXf positions(3, 4);
    // positions.col(0) << -1, -1, 0;
    // positions.col(1) <<  1, -1, 0;
    // positions.col(2) <<  1,  1, 0;
    // positions.col(3) << -1,  1, 0;

    Shade::simpleShader.bind();
    Shade::simpleShader.uploadIndices(Render::cube_inds);
    Shade::simpleShader.uploadAttrib("position", Render::cube_verts);
    // Shade::simpleShader.uploadIndices(indices);
    // Shade::simpleShader.uploadAttrib("position", positions);
    Shade::simpleShader.setUniform("intensity", 0.5f);
    Shade::simpleShader.setUniform("modelViewProj", mvp);
    Shade::simpleShader.drawIndexed(GL_LINES, 0, 24);

    // cout << "DRAW TWO" << endl;
}

void Game::update(float dt) {
    camera->update(dt);
    player->update(dt);
    // TODO
}
