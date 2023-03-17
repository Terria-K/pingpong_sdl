#define SDL_MAIN_HANDLED

#if WINDOWS
#include <Windows.h>
#endif
#include "game.h"
#include <memory>

int main(int argc, char* argv[]) {
#if WINDOWS
    ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif

    auto game = std::make_unique<PingPong::Game>();
    game->run("Ping_Pong", 640, 320, 0);

    return 0;
}