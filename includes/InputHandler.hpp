#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H
#include "Game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_scancode.h>
#include <vector>
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

  private:
    const Uint8 *key_states;
    // InputHandler();
    ~InputHandler() {}
    static InputHandler *_instance;
};
typedef InputHandler TheInputHandler;
#endif
