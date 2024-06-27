#include "../includes/InputHandler.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_gamecontroller.h>
#include <SDL2/SDL_joystick.h>
#include <iostream>

InputHandler *InputHandler::_instance = nullptr;

InputHandler::InputHandler() {
    for (int i = 0; i < 3; i++) {
        this->mouse_button_state.push_back(false);
    }
    this->mouse_pos = new Vector2D(0, 0);
}
void InputHandler::clean() {}

void InputHandler::update() {
    this->key_states = SDL_GetKeyboardState(nullptr);
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            TheGame::Instance()->quit();
            break;
        case SDL_MOUSEBUTTONDOWN: {
            this->on_mouse_button_down(event);
            break;
        }
        case SDL_MOUSEBUTTONUP: {
            this->on_mouse_button_up(event);
            break;
        }
        case SDL_MOUSEMOTION:
            this->on_mouse_move(event);
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
bool InputHandler::get_mouse_button_state(int button_number) {
    return this->mouse_button_state[button_number];
}
Vector2D *InputHandler::get_mouse_position() { return this->mouse_pos; }
void InputHandler::on_mouse_move(SDL_Event &event) {
    this->mouse_pos->setX((float)event.motion.x);
    this->mouse_pos->setY((float)event.motion.y);
}
void InputHandler::on_mouse_button_down(SDL_Event &event) {
    switch (event.button.button) {
    case SDL_BUTTON_LEFT:
        this->mouse_button_state[(size_t)mouse_buttons::LEFT] = true;
        break;
    case SDL_BUTTON_MIDDLE:
        this->mouse_button_state[(size_t)mouse_buttons::MIDDLE] = true;
        break;
    case SDL_BUTTON_RIGHT:
        this->mouse_button_state[(size_t)mouse_buttons::RIGHT] = true;
        break;
    default:
        break;
    }
}
void InputHandler::on_mouse_button_up(SDL_Event &event) {
    switch (event.button.button) {
    case SDL_BUTTON_LEFT:
        this->mouse_button_state[(size_t)mouse_buttons::LEFT] = false;
        break;
    case SDL_BUTTON_MIDDLE:
        this->mouse_button_state[(size_t)mouse_buttons::MIDDLE] = false;
        break;
    case SDL_BUTTON_RIGHT:
        this->mouse_button_state[(size_t)mouse_buttons::RIGHT] = false;
        break;
    default:
        break;
    }
}
