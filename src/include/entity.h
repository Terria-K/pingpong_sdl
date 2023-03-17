#pragma once

#include <memory>
#include "keystate.h"
#include "rect2.h"
#include "texture2d.h"
#include "vector2.h"

namespace PingPong {
    class Entity {
    private:
        std::shared_ptr<Texture2D> tex;
        Rect2<int> rect;

    public:

        Vector2 position;
        Entity(std::shared_ptr<Texture2D> tex, Vector2 pos);
        ~Entity();
        virtual void update(double delta, KeyboardState keyboardState);
        virtual void draw();

        inline Rect2<int> get_rect() {
            return Rect2<int> {
                (int)position.x, (int)position.y, tex->width, tex->height   
            };
        }
    };
}