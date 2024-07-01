#ifndef PLAYER_H_
#define PLAYER_H_
#include "GameObject.hpp"
class Player : public GameObject {
  public:
    Player(LoaderParams *loader_params);
    void draw();
    void update();
    void clean();
    void handle_input();
};
#endif
