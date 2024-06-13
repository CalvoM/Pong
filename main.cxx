#include "includes/Game.hpp"
#include <iostream>
#include <stdlib.h>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
int main(void) {
    Uint32 frame_start, frame_time;
    if (!TheGame::Instance()->sdl_init("SDL Tutorial", 0, 0, 1200, 1920)) {
        std::cout << "SDL Initialization failed!" << std::endl;
    }
    std::cout << "Running..." << std::endl;
    while (TheGame::Instance()->is_running()) {
        frame_start = SDL_GetTicks();
        TheGame::Instance()->render();
        TheGame::Instance()->update();
        TheGame::Instance()->handle_events();
        frame_time = SDL_GetTicks() - frame_start;
        if (frame_time < DELAY_TIME)
            SDL_Delay((int)(DELAY_TIME - frame_time));
    }
    return EXIT_SUCCESS;
}
