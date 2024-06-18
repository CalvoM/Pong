#include "../includes/MenuState.hpp"
#include <iostream>

const std::string MenuState::menu_id = "MENU";

void MenuState::update() {}
void MenuState::render() {}
bool MenuState::on_enter() {
    std::cout << "Entering Menu State" << std::endl;
    return true;
}
bool MenuState::on_exit() {
    std::cout << "Exiting Menu State" << std::endl;
    return true;
}
