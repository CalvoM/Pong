#include "../includes/Game.hpp"
#include "../includes/Resources.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

bool Game::sdl_init(std::string title, int xpos, int ypos, int height,
                    int width) {
  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0) {
    return false;
  }
  this->mainWindow = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height,
                                      SDL_WINDOW_MAXIMIZED);
  if (this->mainWindow == nullptr)
    return false;
  this->mainRenderer = SDL_CreateRenderer(this->mainWindow, -1, 0);
  if (this->mainRenderer == nullptr)
    return false;
  TheTextureManager::Instance()->load(LOAD_RESOURCE(running.png), "animate",
                                      this->mainRenderer);
  return true;
}

void Game::handle_events() {
  if (SDL_PollEvent(&this->event)) {
    switch (this->event.type) {
    case SDL_QUIT:
      this->game_running = false;
      break;
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
      case SDLK_RIGHT:
        this->game_running = true;
        // this->current_frame =
        //     int(((SDL_GetTicks() / 100) % sprite_sheet_count));
        this->_time_counter++;
        this->current_frame = this->_time_counter % this->sprite_sheet_count;
        break;
      case SDLK_LEFT:
        this->_time_counter =
            this->_time_counter == 0 ? 0 : this->_time_counter -= 1;
        this->current_frame = this->_time_counter % this->sprite_sheet_count;
        break;
      default:
        break;
      }
    default:
      this->game_running = true;
    }
  }
}
void Game::render() {
  SDL_RenderClear(mainRenderer);
  TheTextureManager::Instance()->draw("animate", 0, 0, this->sprite_width,
                                      this->sprite_height, this->mainRenderer);
  TheTextureManager::Instance()->drawFrame(
      "animate", this->sprite_width, this->sprite_height - this->sprite_height,
      this->sprite_width, this->sprite_height, 1, this->current_frame,
      this->mainRenderer);
  SDL_RenderPresent(mainRenderer);
}

Game::~Game() {

  IMG_Quit();
  SDL_DestroyRenderer(this->mainRenderer);
  SDL_DestroyWindow(this->mainWindow);
  SDL_Quit();
}
