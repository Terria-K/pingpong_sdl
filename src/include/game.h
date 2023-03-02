#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "entity.h"
#include "keystate.h"
#include "texture2d.h"
#include <SDL_render.h>
#include <SDL_stdinc.h>
#include <SDL_surface.h>
#include <SDL_video.h>
#include <memory>
#include <stdint.h>
#include <string>
#include <vector>

enum GameState { PLAY, EXIT };


class Game {
public:
    Game();
    ~Game();

    void run(const char* title, int width, int height, uint32_t flags);
    std::shared_ptr<Texture2D> load_texture(const char* path, int width, int height);

    void add(std::shared_ptr<Entity> entity);
    
private:
    void draw();
    void dispose();
    void update(KeyboardState state);

    SDL_Window* window;
    SDL_Renderer* renderer;

    int screen_width;
    int screen_height;

    uint64_t now;
    uint64_t last;
    double delta;

    std::vector<std::weak_ptr<Entity>> entities;

    GameState gameState;
};

