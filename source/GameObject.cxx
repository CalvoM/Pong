#include "../includes/GameObject.hpp"
#include "../includes/Game.hpp"
#include "../includes/TextureManager.hpp"
GameObject::GameObject(const LoaderParams *loader_params)
    : BaseGameObject(loader_params) {
    this->xpos = loader_params->get_xpos();
    this->ypos = loader_params->get_ypos();
    this->width = loader_params->get_width();
    this->height = loader_params->get_height();
    this->texture_id = loader_params->get_texture_id();
    this->current_row = 1;
    this->current_frame = 1;
}
void GameObject::draw() {
    TextureManager::Instance()->drawFrame(
        this->texture_id, this->xpos, this->ypos, this->width, this->height,
        this->current_row, this->current_frame,
        TheGame::Instance()->get_renderer());
}
void GameObject::update() { this->xpos++; }
void GameObject::clean() {}
