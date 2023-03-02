#define SDL_MAIN_HANDLED

#include "game.h"
#include <memory>

int main(int argc, char* argv[]) {
    std::unique_ptr<Game> game = std::make_unique<Game>();
    game->run("Ping_Pong", 640, 320, 0);

    return 0;
}