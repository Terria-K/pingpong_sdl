#include "keystate.h"
#include <SDL_scancode.h>

KeyboardState::KeyboardState(const Uint8* keys) {
    this->keys = keys;
}