#include "../includes/Player.hpp"
#include "../includes/InputHandler.hpp"
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_timer.h>
Player::Player(LoaderParams *loader_params) : GameObject(loader_params) {}
void Player::draw() { GameObject::draw(); }
void Player::update() {
    this->current_frame = int(((SDL_GetTicks() / 100) % 15));
    if (TheInputHandler::Instance()->is_key_down(SDL_SCANCODE_RIGHT))
        this->velocity.setX(2);
    if (TheInputHandler::Instance()->is_key_down(SDL_SCANCODE_LEFT))
        this->velocity.setX(-2);
    if (TheInputHandler::Instance()->is_key_down(SDL_SCANCODE_UP))
        this->velocity.setY(-2);
    if (TheInputHandler::Instance()->is_key_down(SDL_SCANCODE_DOWN))
        this->velocity.setY(2);
    GameObject::update();
}
void Player::clean() {}
