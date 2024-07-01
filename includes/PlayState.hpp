#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GameObject.hpp"
#include "GameState.hpp"
#include <vector>
class PlayState : public GameState {
  public:
    virtual void update();
    virtual void render();
    virtual bool on_enter();
    virtual bool on_exit();
    virtual std::string get_state_id() const { return this->play_id; }

  private:
    static const std::string play_id;
    std::vector<GameObject *> game_objects;
};
#endif
