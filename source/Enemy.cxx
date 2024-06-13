#include "../includes/Enemy.hpp"
#include <SDL2/SDL_timer.h>
Enemy::Enemy(LoaderParams *loader_params) : GameObject(loader_params) {}
void Enemy::draw() { GameObject::draw(); }
void Enemy::update() {
    this->xpos++;
    this->ypos--;
    this->current_frame = int(((SDL_GetTicks() / 100) % 6));
}
void Enemy::clean() {}
