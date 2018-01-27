#include <firal/game.h>

Game::Game() : nanogui::Screen(Eigen::Vector2i(800, 800), "Feigns Tale") {
    // TODO
}

Game::~Game() {
    // TODO
}


void Game::initializeGUI() {
    // TODO
}

void Game::initializeWorld() {
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

    currentTime = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(currentTime - startTime);

    update(time_span.count());

    // cout << "DRAW TWO" << endl;
}

void Game::update(float dt) {
    // TODO
}

void Game::clearScreen(NVGcontext* ctx) {
    // clear the screen
    nvgBeginPath(ctx);
    nvgRect(ctx, 0, 0, 1024, 1024);
    nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
    nvgFill(ctx);
}
