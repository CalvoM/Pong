#include "includes/Game.hpp"
#include <iostream>
#include <stdlib.h>

int main(void) {
  Game game;
  if (!game.sdl_init("SDL Tutorial", 0, 0, 720, 1280)) {
    std::cout << "SDL Initialization failed!" << std::endl;
  }
  while (game.is_running()) {
    game.render();
    game.handle_events();
  }
  return EXIT_SUCCESS;
}
