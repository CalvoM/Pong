#include "../includes/Player.hpp"
#include <SDL2/SDL_timer.h>
Player::Player(LoaderParams *loader_params) : GameObject(loader_params) {}
void Player::draw() { GameObject::draw(); }
void Player::update() {
    this->current_frame = int(((SDL_GetTicks() / 100) % 15));
    this->acceleration.setX(1);
    GameObject::update();
}
void Player::clean() {}
