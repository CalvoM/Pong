#ifndef GAME_H_
#define GAME_H_

#include "Enemy.hpp"
#include "GameStateMachine.hpp"
#include "Player.hpp"
#include "TextureManager.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <string>
#include <vector>

enum class GameStateEnum { MENU = 0, PLAY = 1, GAMEOVER = 2 };
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
    GameObject *game_obj;
    GameObject *player_obj;
    std::vector<GameObject *> game_objs;
    GameObject *player;
    GameObject *enemy1;
    GameObject *enemy2;
    GameObject *enemy3;
    static Game *_instance;
    GameStateMachine *game_state_machine;
    GameStateEnum current_game_state;

  public:
    bool sdl_init(std::string title, int xpos, int ypos, int height, int width);
    void render();
    void handle_events();
    void update();
    bool is_running() { return this->game_running; }
    GameStateMachine *get_state_machine() { return this->game_state_machine; }
    void draw();
    static Game *Instance() {
        if (_instance == nullptr) {
            _instance = new Game();
            return _instance;
        }
        return _instance;
    }
    SDL_Renderer *get_renderer() const { return this->mainRenderer; }
    void quit() { this->game_running = false; }
    void clean();
    ~Game();
};

typedef Game TheGame;
#endif
