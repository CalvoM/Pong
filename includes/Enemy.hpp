#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.hpp"
class Enemy : public GameObject {
  public:
    Enemy(LoaderParams *loader_params);
    void draw();
    void update();
    void clean();
};
#endif
