#pragma once
#include <SDL_render.h>
#include <point2.h>
#include <memory>

namespace PingPong {
    class Texture2D {
    private:
        SDL_Renderer* renderer;
        SDL_Texture* tex;
    public:
        void render(Point2 pos);
        Texture2D(SDL_Renderer* renderer, SDL_Texture* tex, int width, int height);
        ~Texture2D();

        int width;
        int height;
    };
}
