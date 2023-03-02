#include "texture2d.h"
#include <SDL_rect.h>
#include <SDL_render.h>


Texture2D::Texture2D(SDL_Renderer* renderer, SDL_Texture* tex, int width, int height) {
    this->width = width;
    this->height = height;
    this->tex = tex;
    this->renderer = renderer;
}
Texture2D::~Texture2D() {
    SDL_DestroyTexture(tex);
}

void Texture2D::render(Point2 pos) {
    SDL_Rect dst {pos.x, pos.y, width, height};
    SDL_RenderCopy(renderer, tex, NULL, &dst);
}
