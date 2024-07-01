#include "../includes/GameObject.hpp"
#include "../includes/Game.hpp"
#include "../includes/TextureManager.hpp"
#include <SDL2/SDL_render.h>
#include <iostream>
GameObject::GameObject(const LoaderParams *loader_params)
    : BaseGameObject(loader_params),
      pos(loader_params->get_xpos(), loader_params->get_ypos()), velocity(0, 0),
      acceleration(0, 0) {
    this->width = loader_params->get_width();
    this->height = loader_params->get_height();
    this->texture_id = loader_params->get_texture_id();
    this->current_row = 1;
    this->current_frame = 1;
}
void GameObject::draw() {
    if (this->velocity.getX() >= 0) {
        TextureManager::Instance()->drawFrame(
            this->texture_id, (int)this->pos.getX(), (int)this->pos.getY(),
            this->width, this->height, this->current_row, this->current_frame,
            TheGame::Instance()->get_renderer());
    } else {
        TextureManager::Instance()->drawFrame(
            this->texture_id, (int)this->pos.getX(), (int)this->pos.getY(),
            this->width, this->height, this->current_row, this->current_frame,
            TheGame::Instance()->get_renderer(), SDL_FLIP_HORIZONTAL);
    }
}
void GameObject::update() {
    this->velocity += this->acceleration;
    this->pos += this->velocity;
}
void GameObject::clean() {}
