#include "../includes/Player.hpp"
#include <SDL2/SDL_timer.h>
Player::Player(LoaderParams *loader_params) : GameObject(loader_params) {}
void Player::draw() { GameObject::draw(); }
void Player::update() {
    this->xpos--;
    this->current_frame = int(((SDL_GetTicks() / 100) % 15));
}
void Player::clean() {}
