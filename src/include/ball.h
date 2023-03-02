#pragma once

#include "bat.h"
#include "entity.h"
#include "rect2.h"
#include "texture2d.h"
#include <memory>

class Ball : public Entity {
public:
    Ball(std::shared_ptr<Texture2D> tex, Vector2 pos, std::weak_ptr<Entity> bat, std::weak_ptr<Entity> bat2);
    ~Ball();

    void update(double delta, KeyboardState keyboardState) override;

private:
    std::weak_ptr<Entity> bat, bat2;
    Rect2<int> rect;
    Vector2 velocity;
    float speed;
};