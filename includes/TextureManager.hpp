#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SDL2/SDL_render.h>
#include <map>
#include <string>

class TextureManager {
public:
  bool load(std::string file_name, std::string id, SDL_Renderer *renderer);
  void draw(std::string id, int xpos, int ypos, int width, int height,
            SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void drawFrame(std::string id, int xpos, int ypos, int width, int height,
                 int current_row, int current_frame, SDL_Renderer *renderer,
                 SDL_RendererFlip flip = SDL_FLIP_NONE);
  static TextureManager *Instance() {
    if (_instance == nullptr) {
      _instance = new TextureManager();
      return _instance;
    }
    return _instance;
  }

private:
  TextureManager() {}
  static TextureManager *_instance;
  std::map<std::string, SDL_Texture *> textureMap;
};

typedef TextureManager TheTextureManager;
#endif
