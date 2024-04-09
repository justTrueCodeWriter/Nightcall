#include "../include/Door.hpp"
#include "../include/ResourceManager.hpp"
#include <iostream>
#include <math.h>

int Door::id_counter = 0;

Door::Door(float x, float y) {
  id = id_counter;
  x_ = x, y_ = y; 
  sprite.setTexture(*ResourceManager::getInstance().getTexture('d'));
  sprite.setTextureRect(sf::IntRect(7, 10, 53, 86));
  sprite.setPosition(x_, y_);
  id_counter++;
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
        if (message->activate.id == id)
          isOpen = !isOpen;
        break;
    }
}
