#include "entity.h"
#include "keystate.h"
#include "rect2.h"
#include <memory>
#include <utility>

namespace PingPong {

    Entity::Entity(std::shared_ptr<Texture2D> tex, Vector2 pos) {
        this->tex = std::move(tex);
        this->position = pos;
    }

    Entity::~Entity() {}

    void Entity::update(double delta, KeyboardState keyboardState) {}
    void Entity::draw() { 
        tex->render(position.convert_to_point()); 
    }
}

