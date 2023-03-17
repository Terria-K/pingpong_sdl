#pragma once
#include "entity.h"
#include "keystate.h"
#include "rect2.h"
#include "texture2d.h"
#include "vector2.h"
#include <SDL_scancode.h>
#include <memory>

namespace PingPong {

    class Bat : public Entity {
    public:

        Bat(std::shared_ptr<Texture2D> tex, Vector2 pos, SDL_Scancode up, SDL_Scancode down);
        ~Bat();
        void update(double delta, KeyboardState keyboardState) override;

    private:

        SDL_Scancode up;
        SDL_Scancode down;
        int axis = 0;
    };

}
