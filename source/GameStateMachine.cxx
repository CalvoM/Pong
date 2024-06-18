#include "../includes/GameStateMachine.hpp"

void GameStateMachine::push_state(GameState *state) {
    this->game_states.push_back(state);
    this->game_states.back()->on_enter();
}

void GameStateMachine::pop_state() {
    if (!this->game_states.empty()) {
        if (this->game_states.back()->on_exit()) {
            delete this->game_states.back();
            this->game_states.pop_back();
        }
    }
}

void GameStateMachine::change_state(GameState *state) {
    if (!this->game_states.empty()) {
        if (this->game_states.back()->get_state_id() == state->get_state_id()) {
            return;
        }
        if (this->game_states.back()->on_exit()) {
            delete this->game_states.back();
            this->game_states.pop_back();
        }
        this->game_states.push_back(state);
        this->game_states.back()->on_enter();
    }
}

void GameStateMachine::update() {
    if (!this->game_states.empty()) {
        this->game_states.back()->update();
    }
}
void GameStateMachine::render() {
    if (!this->game_states.empty()) {
        this->game_states.back()->render();
    }
}
