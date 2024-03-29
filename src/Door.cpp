#include "../include/Door.hpp"
#include "../include/ResourceManager.hpp"
#include <math.h>

Door::Door(float x, float y) {
  x_ = x, y_ = y; 
  sprite.setTexture(*ResourceManager::getInstance().getTexture('d'));
  sprite.setTextureRect(sf::IntRect(7, 10, 53, 86));
  sprite.setPosition(x_, y_);
}

Door::~Door() {
}

void Door::update(float time) {

  if (isOpen) {
    sprite.setTextureRect(sf::IntRect(415, 106, 53, 86));
  }
  else if (!isOpen) {
    sprite.setTextureRect(sf::IntRect(7, 10, 53, 86));
  }
}

// char Door::getType() { return 'd'; }

void Door::sendMessage(Message* message) {
    if (message->sender == this) return;
    switch (message->action) {
      case ACTIVATE:

        break;
    }
}
