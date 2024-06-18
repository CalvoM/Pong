#include "../includes/PlayState.hpp"
#include <iostream>
const std::string PlayState::play_id = "PLAY";

void PlayState::update() {}
void PlayState::render() {}
bool PlayState::on_enter() {
    std::cout << "Entering Play State" << std::endl;
    return true;
}
bool PlayState::on_exit() {
    std::cout << "Exiting Play State" << std::endl;
    return true;
}
