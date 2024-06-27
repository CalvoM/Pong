#include "../includes/MenuButton.hpp"
#include "../includes/InputHandler.hpp"
#include <iostream>

MenuButton::MenuButton(const LoaderParams *loader_params)
    : GameObject(loader_params) {
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
            std::cout << "Clicked" << std::endl;
            current_frame = button_state::CLICKED;
        }
    } else {
        this->current_frame = button_state::MOUSE_OUT;
    }
}
void MenuButton::clean() { GameObject::clean(); }
