#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H
#include "Game.hpp"
#include "Vector2D.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_scancode.h>
#include <cstddef>
#include <vector>

enum class mouse_buttons : size_t { LEFT = 0, MIDDLE = 1, RIGHT = 2 };
class InputHandler {
  public:
    static InputHandler *Instance() {
        if (_instance == nullptr) {
            _instance = new InputHandler();
        }
        return _instance;
    }
    void update();
    void clean();
    bool is_key_down(SDL_Scancode key);
    bool get_mouse_button_state(int button_number);
    Vector2D *get_mouse_position();

  private:
    const Uint8 *key_states;
    std::vector<bool> mouse_button_state;
    InputHandler();
    ~InputHandler() {}
    static InputHandler *_instance;
    Vector2D *mouse_pos = nullptr;
    void on_mouse_move(SDL_Event &event);
    void on_mouse_button_down(SDL_Event &event);
    void on_mouse_button_up(SDL_Event &event);
};
typedef InputHandler TheInputHandler;
#endif
