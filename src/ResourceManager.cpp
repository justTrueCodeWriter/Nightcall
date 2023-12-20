#include "../include/ResourceManager.hpp"

void ResourceManager::loadTextures() {
  sf::Texture texture;
  for (const std::string filename : {"media/img/background.png",
                                     "media/img/Fifteen.png",
                                     "media/img/usual_tile.png",
                                     }) {
    texture.loadFromFile(filename);
    textures.push_back(texture);
  }
}

sf::Texture ResourceManager::getTexture(char message) {

  for (int i = 0; i < textures.capacity(); i++) {
    if (possibleTypes[i] == message) {
      return textures[i];
    }
  }

  return sf::Texture();

}
