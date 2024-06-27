#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "GameObject.hpp"
#include "GameState.hpp"
#include <vector>
class MenuState : public GameState {
  public:
    virtual void update();
    virtual void render();
    virtual bool on_enter();
    virtual bool on_exit();
    virtual std::string get_state_id() const { return this->menu_id; }

  private:
    static const std::string menu_id;
    std::vector<GameObject *> game_objects;
};
#endif
