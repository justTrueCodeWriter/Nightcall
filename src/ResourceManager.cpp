#include "../include/ResourceManager.hpp"
#include <iostream>
#include <vector>

void ResourceManager::loadTextures() {

  std::vector<std::string> filenames = {
    "media/img/background.png",
    "media/img/Fifteen.png",
    "media/img/usual_tile.png"};

  for (auto filename : filenames) {
    sf::Texture texture;
    std::cout << texture.loadFromFile(filename) << std::endl;
    textures.push_back(texture);

    std::cout << "test" << std::endl;
  }
}

sf::Texture *ResourceManager::getTexture(char message) {
/*
  for (int i = 0; i < textures.capacity(); i++) {
    if (possibleObjectTypes_[i] == message) {
      return textures[i];
    }
  }

  return nullptr;
*/
}
