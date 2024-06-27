#include "../includes/TextureManager.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <iostream>

TextureManager *TextureManager::_instance = nullptr;

bool TextureManager::load(std::string file_name, std::string id,
                          SDL_Renderer *renderer) {
    SDL_Surface *temp_surface = IMG_Load(file_name.c_str());
    if (temp_surface == 0)
        return false;
    SDL_Texture *temp_texture =
        SDL_CreateTextureFromSurface(renderer, temp_surface);
    SDL_FreeSurface(temp_surface);
    if (temp_texture != 0) {
        textureMap[id] = temp_texture;
        return true;
    }
    return false;
}
void TextureManager::draw(std::string id, int xpos, int ypos, int width,
                          int height, SDL_Renderer *renderer,
                          SDL_RendererFlip flip) {
    SDL_Rect src_rect;
    SDL_Rect dest_rect;
    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.w = dest_rect.w = width;
    src_rect.h = dest_rect.h = height;
    dest_rect.x = xpos;
    dest_rect.y = ypos;
    SDL_RenderCopyEx(renderer, textureMap[id], &src_rect, &dest_rect, 0,
                     nullptr, flip);
}
void TextureManager::drawFrame(std::string id, int xpos, int ypos, int width,
                               int height, int current_row, int current_frame,
                               SDL_Renderer *renderer, SDL_RendererFlip flip) {
    SDL_Rect src_rect;
    SDL_Rect dest_rect;
    src_rect.x = width * current_frame;
    src_rect.y = height * (current_row - 1);
    src_rect.w = dest_rect.w = width;
    src_rect.h = dest_rect.h = height;
    dest_rect.x = xpos;
    dest_rect.y = ypos;
    int ret = SDL_RenderCopyEx(renderer, textureMap[id], &src_rect, &dest_rect,
                               0, nullptr, flip);
}
void TextureManager::clear_from_textureMap(std::string id) {
    this->textureMap.erase(id);
}
TextureManager::~TextureManager() {}
