#include "ball.h"
#include "rect2.h"
#include "tmath.h"
#include <memory>

Ball::Ball(
    std::shared_ptr<Texture2D> tex, Vector2 pos, std::weak_ptr<Entity> bat, std::weak_ptr<Entity> bat2) : Entity(tex, pos) 
{
    this->bat = bat;
    this->bat2 = bat2;
    velocity = Vector2 {1.0f, 1.0f} ;
    speed = 0.2;
}
Ball::~Ball() {}


void Ball::update(double delta, KeyboardState keyboardState) {
    float final_velocity_x = velocity.x * speed * delta;
    float final_velocity_y = velocity.y * speed * delta;
    position.x += final_velocity_x;
    position.y += final_velocity_y;
    if (position.y <= 0) {
        velocity.y *= -1;
    }
    if (position.y >= (320 - 16)) {
        velocity.y *= -1;
    }
    if (get_rect().contains(bat.lock()->get_rect())) {
        speed = 0.2;
        velocity.x *= -1;
    }
    if (get_rect().contains(bat2.lock()->get_rect())) {
        speed = 0.2;
        velocity.x *= -1;
    }
    
    if (position.x <= -32) {
        position = Vector2 { (640 * 0.5) - 16, (320 * 0.5) - 16 };
        speed += 0.01;
        velocity.x = -1;
    }
    if (position.x >= 640 + 32) {
        position = Vector2 { (640 * 0.5) - 16, (320 * 0.5) - 16 };
        speed += 0.01;
        velocity.x = 1;
    }
}