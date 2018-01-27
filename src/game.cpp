#include <firal/game.h>
#include <firal/shade.h>
#include <firal/render.h>
#include <firal/util.h>

Game::Game() : nanogui::Screen(Eigen::Vector2i(800, 800), "Feigns Tale") {
    initializeGUI();
    initializeWorld();
}

Game::~Game() {
    // TODO
}


void Game::initializeGUI() {
    // TODO

    performLayout();
}

void Game::initializeWorld() {
    Shade::initialize();
    Render::initialize();

    player = new Player();
    camera = new Camera();

    player->setPosition(Vector3f(0f, 0f, 0f));
    camera->setPosition(Vector3f(0f, 0f, -5f));

    aspect = 1.f;

    // TODO
}


bool Game::keyboardEvent(int key, int scancode, int action, int modifiers) {
    // TODO
    return false;
}

bool Game::mouseButtonEvent(const Vector2i &p, int button, bool down, int modifiers) {
    // TODO
    return false;
}

bool Game::mouseDragEvent(const Vector2i &p, const Vector2i &rel, int button, int modifiers) {
    // TODO
    return false;
}

bool Game::scrollEvent(const Vector2i &p, const Vector2f &rel) {
    // TODO
    return false;
}

// TODO - maybe modify nanogui to allow for different update and draw loops
void Game::draw(NVGcontext *ctx) {
    clearScreen(ctx);

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

    update(time_span.count());

    Matrix4f mvp;
    mvp.setIdentity();

    Matrix4f model = rotate(glfwGetTime(), 1, 1, 1) * scale(0.25f, 0.25f, 0.25f);
    Matrix4f view = camera->lookAt(player);
    Matrix4f proj = perspective(); // GOTTA GO

    // Matrix3f zrot = Matrix3f(Eigen::AngleAxisf((float) glfwGetTime(),  Vector3f::UnitZ())) * 0.25f;
    // Matrix3f yrot = Matrix3f(Eigen::AngleAxisf((float) glfwGetTime(),  Vector3f::UnitY())) * 0.25f;
    // mvp.topLeftCorner<3,3>() = zrot * yrot;

    mvp = rotate(glfwGetTime(), 1, 1, 1) * scale(0.25f, 0.25f, 0.25f);

    mvp.row(0) *= (float) mSize.y() / (float) mSize.x();


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
    // TODO
}

void Game::clearScreen(NVGcontext* ctx) {
    // clear the screen
    // nvgBeginPath(ctx);
    // nvgRect(ctx, 0, 0, 1024, 1024);
    // nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
    // nvgFill(ctx);
}
