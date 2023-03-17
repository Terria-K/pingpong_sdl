#include "keystate.h"
#include <SDL_scancode.h>

namespace PingPong {
    KeyboardState::KeyboardState(const Uint8* keys) {
        this->keys = keys;
    }
}

