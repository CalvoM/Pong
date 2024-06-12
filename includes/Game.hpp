#ifndef GAME_H_
#define GAME_H_

#include "TextureManager.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <string>

enum class IMG_TYPE { PNG, JPG, WEBP, BITMAP, TIF, AVIF };
class Game {
private:
  SDL_Window *mainWindow = nullptr;
  SDL_Event event;
  SDL_Renderer *mainRenderer = nullptr;
  SDL_Rect sourceRect;
  SDL_Rect destRect;
  bool game_running;
  int sprite_height = 564;
  int sprite_width = 614;
  int sprite_sheet_count = 15;
  int current_frame;
  int _time_counter = 0;

public:
  bool sdl_init(std::string title, int xpos, int ypos, int height, int width);
  void render();
  void handle_events();
  bool is_running() { return this->game_running; }
  ~Game();
};
#endif
