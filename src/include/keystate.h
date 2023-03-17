#pragma once

#include <SDL_scancode.h>
#include <SDL_stdinc.h>

namespace PingPong {
    struct KeyboardState {
        KeyboardState(const Uint8* keys);
        const Uint8* keys;
    };
}
