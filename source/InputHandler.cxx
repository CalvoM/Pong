#include "../includes/InputHandler.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_gamecontroller.h>
#include <SDL2/SDL_joystick.h>
#include <iostream>

InputHandler *InputHandler::_instance = nullptr;
void InputHandler::clean() {}

void InputHandler::update() {
    this->key_states = SDL_GetKeyboardState(nullptr);
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            TheGame::Instance()->quit();
            break;
        default:
            break;
        }
    }
}
bool InputHandler::is_key_down(SDL_Scancode key) {
    if (this->key_states != 0) {
        if (this->key_states[key] == 1)
            return true;
        else
            return false;
    }
    return false;
}
