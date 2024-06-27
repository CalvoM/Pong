#include "../includes/MenuState.hpp"
#include "../includes/Game.hpp"
#include "../includes/MenuButton.hpp"
#include "../includes/Resources.hpp"
#include "../includes/TextureManager.hpp"
#include <iostream>

const std::string MenuState::menu_id = "MENU";

void MenuState::update() {
    for (int i = 0; i < this->game_objects.size(); i++) {
        game_objects[i]->update();
    }
}
void MenuState::render() {
    for (int i = 0; i < this->game_objects.size(); i++) {
        game_objects[i]->draw();
    }
}
bool MenuState::on_enter() {
    if (!TheTextureManager::Instance()->load(
            LOAD_RESOURCE(start_sheet.png), "playbutton",
            TheGame::Instance()->get_renderer())) {
        return false;
    }
    if (!TheTextureManager::Instance()->load(
            LOAD_RESOURCE(pause_sheet.png), "pausebutton",
            TheGame::Instance()->get_renderer())) {
        return false;
    }
    GameObject *play_button =
        new MenuButton(new LoaderParams(960, 500, 108, 48, "playbutton"));
    GameObject *pause_button =
        new MenuButton(new LoaderParams(960, 600, 108, 48, "pausebutton"));
    this->game_objects.push_back(play_button);
    this->game_objects.push_back(pause_button);

    std::cout << "Entering Menu State" << std::endl;
    return true;
}
bool MenuState::on_exit() {
    for (int i = 0; i < this->game_objects.size(); i++) {
        this->game_objects[i]->clean();
    }
    this->game_objects.clear();
    // TODO: Clear Textures
    TheTextureManager::Instance()->clear_from_textureMap("playbutton");
    TheTextureManager::Instance()->clear_from_textureMap("pausebutton");
    std::cout << "Exiting Menu State" << std::endl;
    return true;
}
