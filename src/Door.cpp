#include "../include/Door.hpp"
#include "../include/ResourceManager.hpp"

Door::Door(float x, float y) {
  x_ = x, y_ = y; 
  sprite.setTexture(*ResourceManager::getInstance().getTexture('d'));
  sprite.setTextureRect(sf::IntRect(7, 10, 53, 86));
  sprite.setPosition(x_, y_);
}

void Door::update(float time) {

  if (message_.object_type == 'b' && message_.action == ACTIVATE) {
    isOpen = !isOpen;
  }

  if (isOpen) {
    sprite.setTextureRect(sf::IntRect(415, 106, 53, 86));
  }
  else if (!isOpen) {
    sprite.setTextureRect(sf::IntRect(7, 10, 53, 86));
  }
}

char Door::getType() { return 'd'; }
