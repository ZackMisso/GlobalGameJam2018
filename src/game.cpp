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
    test = new Tree();

    camera->setInput(input);
    camera->setPosition(Vector3f(0.f, 0.f, -5.f));

    player->setPosition(Vector3f(0.f, 0.f, 0.f));
    test->setPosition(Vector3f(0.f, 0.f, 0.f));

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

    glEnable(GL_DEPTH_TEST);

    currentTime = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(currentTime - startTime);

    float dt = time_span.count();

    update(dt);

    // Matrix4f mvp;
    // mvp.setIdentity();

    // flat shading
    // Matrix4f model = rotate(glfwGetTime(), 1, 1, 1) * scale(0.25f, 0.25f, 0.25f);
    // Matrix4f view = camera->lookAt(player);
    // Matrix4f proj = perspective(120.f, aspect, 0.2f, 100.f);
    //
    // mvp = proj * view * model;
    //
    // Shade::simpleShader.bind();
    // Shade::simpleShader.uploadIndices(Render::cube_inds);
    // Shade::simpleShader.uploadAttrib("position", Render::cube_verts);
    // Shade::simpleShader.setUniform("intensity", 0.5f);
    // Shade::simpleShader.setUniform("modelViewProj", mvp);
    // Shade::simpleShader.drawIndexed(GL_TRIANGLES, 0, 12);

    // blinnPhong
    Matrix4f model = rotate(glfwGetTime(), 1, 1, 1) * scale(0.25f, 0.25f, 0.25f);
    Matrix4f view = camera->lookAt(player);
    Matrix4f proj = perspective(120.f, aspect, 0.2f, 100.f);

    Matrix4f vp = proj * view;
    Matrix4f invView = view.inverse();

    test->render(vp, invView);

    // Matrix4f mvp = vp * model;
    // // Matrix4f invView = view.inverse();
    // Matrix4f normMat = model.inverse().transpose();
    // Vector3f lightPos = camera->getPosition();
    //
    // Shade::phongShader.bind();
    // Shade::phongShader.uploadIndices(Render::cube_inds);
    // Shade::phongShader.uploadAttrib("pos", Render::cube_verts);
    // Shade::phongShader.uploadAttrib("norm", Render::cube_norms);
    // Shade::phongShader.setUniform("mvpMatrix", mvp);
    // Shade::phongShader.setUniform("mMatrix", model);
    // Shade::phongShader.setUniform("nMatrix", normMat);
    // Shade::phongShader.setUniform("invViewMatrix", invView);
    // Shade::phongShader.setUniform("lightPos", lightPos);
    // Shade::phongShader.drawIndexed(GL_TRIANGLES, 0, 12);


}

void Game::update(float dt) {
    camera->update(dt);
    player->update(dt);
    // TODO
}
