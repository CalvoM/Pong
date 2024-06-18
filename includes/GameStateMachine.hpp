#ifndef GAME_STATE_MACHINE_H
#define GAME_STATE_MACHINE_H
#include "GameState.hpp"
#include <vector>
class GameStateMachine {
  public:
    void push_state(GameState *state);
    void change_state(GameState *state);
    void pop_state();
    void update();
    void render();

  private:
    std::vector<GameState *> game_states;
};
#endif
