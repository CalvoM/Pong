#include "../includes/Game.hpp"
#include "../includes/InputHandler.hpp"
#include "../includes/MenuState.hpp"
#include "../includes/PlayState.hpp"
#include "../includes/Resources.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>

Game *Game::_instance = nullptr;

bool Game::sdl_init(std::string title, int xpos, int ypos, int height,
                    int width) {
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0) {
        return false;
    }
    this->mainWindow = SDL_CreateWindow(title.c_str(), xpos, ypos, width,
                                        height, SDL_WINDOW_SHOWN);
    if (this->mainWindow == nullptr)
        return false;
    this->mainRenderer = SDL_CreateRenderer(this->mainWindow, -1, 0);
    if (this->mainRenderer == nullptr)
        return false;
    // TheTextureManager::Instance()->load(LOAD_RESOURCE(running.png),
    // "animate",
    //                                     this->mainRenderer);
    // this->game_obj = new Player(new LoaderParams(
    //     0, 0, this->sprite_width, this->sprite_height, "animate"));
    // this->player_obj = new Player(new LoaderParams(
    //     600, 300, this->sprite_width, this->sprite_height, "animate"));
    // this->enemy1 = new Enemy(new LoaderParams(600, 600, this->sprite_width,
    //                                           this->sprite_height,
    //                                           "animate"));
    // this->game_objs.push_back(this->game_obj);
    // this->game_objs.push_back(this->player_obj);
    // this->game_objs.push_back(this->enemy1);
    this->game_running = true;
    this->current_game_state = GameStateEnum::MENU;
    this->game_state_machine = new GameStateMachine();
    this->game_state_machine->change_state(new MenuState());
    return true;
}

void Game::handle_events() {
    TheInputHandler::Instance()->update();
    if (InputHandler::Instance()->is_key_down(SDL_SCANCODE_RETURN)) {
        this->game_state_machine->change_state(new PlayState());
    }
    // if (SDL_PollEvent(&this->event)) {
    //     switch (this->event.type) {
    //     case SDL_QUIT:
    //         this->game_running = false;
    //         break;
    //     case SDL_KEYDOWN:
    //         switch (event.key.keysym.sym) {
    //         case SDLK_RIGHT:
    //             this->game_running = true;
    //             // this->current_frame =
    //             //     int(((SDL_GetTicks() / 100) % sprite_sheet_count));
    //             this->_time_counter++;
    //             this->current_frame =
    //                 this->_time_counter % this->sprite_sheet_count;
    //             break;
    //         case SDLK_LEFT:
    //             this->_time_counter =
    //                 this->_time_counter == 0 ? 0 : this->_time_counter -= 1;
    //             this->current_frame =
    //                 this->_time_counter % this->sprite_sheet_count;
    //             break;
    //         default:
    //             break;
    //         }
    //     default:
    //         this->game_running = true;
    //     }
    // }
}
void Game::render() {
    SDL_RenderClear(mainRenderer);
    this->game_state_machine->render();
    SDL_RenderPresent(this->mainRenderer);
}

void Game::update() { this->game_state_machine->update(); }

void Game::draw() {
    if (!this->game_objs.empty()) {
        for (std::vector<GameObject *>::size_type i = 0; i != game_objs.size();
             i++) {
            game_objs[i]->draw();
        }
    }
}

void Game::clean() { TheInputHandler::Instance()->clean(); }

Game::~Game() {

    IMG_Quit();
    SDL_DestroyRenderer(this->mainRenderer);
    SDL_DestroyWindow(this->mainWindow);
    SDL_Quit();
}
