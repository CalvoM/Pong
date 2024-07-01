#ifndef MENU_BUTTON_H_
#define MENU_BUTTON_H_
#include "GameObject.hpp"
class MenuButton : public GameObject {
  public:
    MenuButton(const LoaderParams *loader_params, void (*callback)());
    virtual void draw();
    virtual void update();
    virtual void clean();

  private:
    enum class button_state { MOUSE_OUT = 0, MOUSE_OVER = 1, CLICKED = 2 };
    button_state current_frame;
    void (*call_back)();
    bool button_released;
};
#endif
