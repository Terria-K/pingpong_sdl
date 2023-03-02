#include "bat.h"
#include "entity.h"
#include "keystate.h"
#include "rect2.h"
#include "texture2d.h"
#include "tmath.h"
#include "vector2.h"
#include <SDL_scancode.h>
#include <memory>

Bat::Bat(std::shared_ptr<Texture2D> tex, Vector2 pos, SDL_Scancode up, SDL_Scancode down) : Entity(tex, pos) {
    this->up = up;
    this->down = down;
}
Bat::~Bat() {}

void Bat::update(double delta, KeyboardState keyboardState) {
    if (keyboardState.keys[this->up]) {
        axis = -1;
    }
    else if (keyboardState.keys[this->down]) {
        axis = 1;
    }
    float final_axis = axis * 0.2 * delta;
    position.y = clamp(position.y + final_axis, 0.0f, 320.0f - 100); 
    axis = 0;
}