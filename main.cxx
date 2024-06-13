#include "includes/Game.hpp"
#include <iostream>
#include <stdlib.h>

int main(void) {
    if (!TheGame::Instance()->sdl_init("SDL Tutorial", 0, 0, 1200, 1920)) {
        std::cout << "SDL Initialization failed!" << std::endl;
    }
    std::cout << "Running..." << std::endl;
    while (TheGame::Instance()->is_running()) {
        TheGame::Instance()->render();
        TheGame::Instance()->update();
        TheGame::Instance()->handle_events();
        SDL_Delay(50);
    }
    return EXIT_SUCCESS;
}
