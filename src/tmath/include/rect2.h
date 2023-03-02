#pragma once

template<typename T>
struct Rect2 { 
    T x; T y;
    T w; T h;

    bool contains(Rect2<T> rect) {
        return
        this->x < rect.x + rect.w &&
        this->x + this->w > rect.x &&
        this->y < rect.y + rect.h &&
        this->y + this->h > rect.y;
    }

    bool contains_with_pos(Rect2<T> rect) {
        return
        this->x < rect.x + rect.w &&
        this->x + this->w > rect.x &&
        this->y < rect.y + rect.h &&
        this->y + this->h > rect.y;
    }
};