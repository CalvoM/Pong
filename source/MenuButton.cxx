#include "../includes/MenuButton.hpp"
#include "../includes/InputHandler.hpp"
#include <iostream>

MenuButton::MenuButton(const LoaderParams *loader_params, void (*callback)())
    : GameObject(loader_params), call_back(callback) {
    this->current_frame = button_state::MOUSE_OUT;
}

void MenuButton::draw() { GameObject::draw(); }
void MenuButton::update() {
    Vector2D *mouse_pos = TheInputHandler::Instance()->get_mouse_position();
    if (mouse_pos->getX() < (this->pos.getX() + width) &&
        mouse_pos->getX() > pos.getX() &&
        mouse_pos->getY() < (pos.getY() + height) &&
        mouse_pos->getY() > pos.getY()) {
        this->current_frame = button_state::MOUSE_OVER;
        if (TheInputHandler::Instance()->get_mouse_button_state(
                (size_t)mouse_buttons::LEFT)) {
            current_frame = button_state::CLICKED;
            this->call_back();
            this->button_released = false;
        }
    } else if (!TheInputHandler::Instance()->get_mouse_button_state(
                   (size_t)mouse_buttons::LEFT)) {
        this->button_released = true;
        this->current_frame = button_state::MOUSE_OVER;
    } else {
        this->current_frame = button_state::MOUSE_OUT;
    }
}
void MenuButton::clean() { GameObject::clean(); }
