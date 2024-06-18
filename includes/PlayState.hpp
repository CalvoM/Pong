#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GameState.hpp"
class PlayState : public GameState {
  public:
    virtual void update();
    virtual void render();
    virtual bool on_enter();
    virtual bool on_exit();
    virtual std::string get_state_id() const { return this->play_id; }

  private:
    static const std::string play_id;
};
#endif
