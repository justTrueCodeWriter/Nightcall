#include "../include/ResourceManager.hpp"
#include <iostream>
#include <vector>

ResourceManager::ResourceManager() {
  std::vector<std::string> filenames = {
    "media/img/background.png",
    "media/img/menu_background.png",
    "media/img/fifteen.png",
    "media/img/usual_tile.png",
    "media/img/swordsman.png",
    "media/img/button.png",
    "media/img/door.png",
    "media/img/usual_spikes.png"};

  for (auto filename : filenames) {
    sf::Texture texture;
    texture.loadFromFile(filename);
    textures.push_back(texture);
  }
}

sf::Texture *ResourceManager::getTexture(char message) {
  for (int i = 0; i < textures.capacity(); i++) {
    if (possibleObjectTypes_[i] == message) {
      return &textures[i];
    }
  }

  return nullptr;
}
