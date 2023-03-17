#include "game.h"
#include "ball.h"
#include "bat.h"
#include "entity.h"
#include "keystate.h"
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_image.h>
#include <SDL_keyboard.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_scancode.h>
#include <SDL_surface.h>
#include <SDL_timer.h>
#include <SDL_video.h>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdint.h>
#include <time.h>

namespace PingPong {
    constexpr uint64_t delta_scale = 1000;

    Game::Game() {
        screen_width = 1024;
        screen_height = 600;
        gameState = GameState::PLAY;
        now = SDL_GetPerformanceCounter();
        last = 0;
        delta = 0;
    }
    Game::~Game() {
        dispose();
    }

    void Game::run(const char* title, int width, int height, uint32_t flags) {
        std::srand((uint32_t)time(NULL));
        // Initializiation for SDL
        this->screen_width = width;
        this->screen_height = height;
        SDL_Init SDL_INIT_EVERYTHING;

        window =  SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, flags);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        // Initialization for the game
        // resources
        auto bat_tex = load_texture("res/bat.png", 16, 100);
        auto ball_tex = load_texture("res/ball.png", 16, 16);

        // entities
        std::shared_ptr<Entity> bat = std::make_shared<Bat>(
            bat_tex, Vector2 { 16, 30 }, SDL_SCANCODE_W, SDL_SCANCODE_S);
        std::shared_ptr<Entity> bat2 = std::make_shared<Bat>(
            bat_tex, Vector2 { 608, 30 }, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);
        std::shared_ptr<Entity> ball = std::make_shared<Ball>(
            ball_tex, Vector2 { (640 * 0.5) - 16, (320 * 0.5) - 16 }, bat, bat2);
        add(bat);
        add(bat2);
        add(ball);

        // event
        while (gameState != GameState::EXIT) {
            last = now;
            now = SDL_GetPerformanceCounter();
            delta = ((now - last) * delta_scale / (double)SDL_GetPerformanceFrequency());
            SDL_Event evt;
            SDL_PollEvent(&evt);

            switch (evt.type) {
                case SDL_QUIT: 
                    gameState = GameState::EXIT;
                    break;
            }
            KeyboardState keyboardState { SDL_GetKeyboardState(nullptr) };
            update(keyboardState);
            draw();
        }
    }

    void Game::update(KeyboardState keyboardState) {
        for (auto entity : entities) {
            entity.lock()->update(delta, keyboardState);
        }
    }


    void Game::draw() {
        for (auto entity : entities) {
            entity.lock()->draw();
        }
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    void Game::add(std::shared_ptr<Entity> entity) {
        entities.push_back(entity);
    }

    void Game::dispose() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
    }

    std::shared_ptr<Texture2D> Game::load_texture(const char* path, int width, int height) {
        SDL_Texture* tex = IMG_LoadTexture(renderer, path);
        if (tex == NULL) {
            std::cout << "img couldn't load from file path: " << path << " Error: " << SDL_GetError() << std::endl;
            throw;
        }
        return std::make_shared<Texture2D>(renderer, tex, width, height);
    }
}
