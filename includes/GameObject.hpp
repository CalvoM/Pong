#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <SDL2/SDL_render.h>
#include <string>

class LoaderParams {
  public:
    LoaderParams(int xpos, int ypos, int width, int height,
                 std::string texture_id)
        : xpos(xpos), ypos(ypos), width(width), height(height),
          texture_id(texture_id) {}
    int get_xpos() const { return this->xpos; };
    int get_ypos() const { return this->ypos; };
    int get_width() const { return this->width; };
    int get_height() const { return this->height; };
    std::string get_texture_id() const { return this->texture_id; }

  private:
    int xpos;
    int ypos;
    int width;
    int height;
    std::string texture_id;
};

class BaseGameObject {
  public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;

  protected:
    BaseGameObject(const LoaderParams *loader_params) {}
    virtual ~BaseGameObject() {}
};
class GameObject : public BaseGameObject {
  public:
    GameObject(const LoaderParams *loader_params);
    virtual void draw();
    virtual void update();
    virtual void clean();

  protected:
    int xpos;
    int ypos;
    int width;
    int height;
    int current_frame;
    int current_row;
    std::string texture_id;
};
#endif
