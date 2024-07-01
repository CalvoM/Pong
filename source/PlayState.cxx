#include "../includes/PlayState.hpp"
#include "../includes/Game.hpp"
#include "../includes/Resources.hpp"
#include "../includes/TextureManager.hpp"
#include <iostream>
const std::string PlayState::play_id = "PLAY";
void PlayState::update() {
    for (int i = 0; i < this->game_objects.size(); i++) {
        game_objects[i]->update();
    }
}
void PlayState::render() {
    for (int i = 0; i < this->game_objects.size(); i++) {
        game_objects[i]->draw();
    }
}
bool PlayState::on_enter() {
    if (!TheTextureManager::Instance()->load(
            LOAD_RESOURCE(running.png), "ninja_running",
            TheGame::Instance()->get_renderer())) {
        return false;
    }
    GameObject *ninja =
        new Player(new LoaderParams(100, 100, 614, 564, "ninja_running"));
    this->game_objects.push_back(ninja);
    std::cout << "PlayState entering" << std::endl;
    return true;
}
bool PlayState::on_exit() {
    for (int i = 0; i < this->game_objects.size(); i++) {
        game_objects[i]->clean();
    }
    this->game_objects.clear();
    TheTextureManager::Instance()->clear_from_textureMap("ninja_running");
    std::cout << "Exiting Play State" << std::endl;
    return true;
}
