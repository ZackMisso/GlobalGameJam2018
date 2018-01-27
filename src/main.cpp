#include <firal/common.h>
#include <firal/random.h>
#include <firal/game.h>

int main(int argc, char* argv[]) {
    // cout << "HELLO LORD FIRAL" << endl;

    Random::initialize();

    try {
        nanogui::init();
        {
            nanogui::ref<Game> game = new Game();
            game->drawAll();
            game->setVisible(true);
            nanogui::mainloop(16);
        }
        nanogui::shutdown();
    } catch (const std::runtime_error &e) {
        std::string error_msg = std::string("Caught a fatal error: ") + std::string(e.what());
        std::cerr << error_msg << endl;
        return -1;
    }

    return 0;
}
