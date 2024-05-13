#include "../include/Door.hpp"
#include "../include/Game.hpp"
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

Door::~Door() {}

void Door::update(float time) {

  if (isOpen) {
    sprite.setTextureRect(sf::IntRect(415, 106, 53, 86));
  } else if (!isOpen) {
    sprite.setTextureRect(sf::IntRect(7, 10, 53, 86));
  }
}

// char Door::getType() { return 'd'; }

void Door::sendMessage(Message *message) {
  if (message->sender == this)
    return;
  switch (message->action) {
  case ATTACK:
      if (message->sender->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()))
        isOpen = true;
    break;
  case MOVE:
    if (message->sender->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()) && !isOpen) { 
      Message *msg = new Message;
      msg->sender = this;
      msg->action = COLLIDE;
      if (message->sender->getSprite().getGlobalBounds().left < sprite.getGlobalBounds().left) {
        msg->collide.direction = LEFT;
        std::cout << "left" << std::endl;
      } 
      else if (message->sender->getSprite().getGlobalBounds().left + msg->sender->getSprite().getGlobalBounds().width > sprite.getGlobalBounds().left + sprite.getGlobalBounds().width) {
        msg->collide.direction = RIGHT;
        std::cout << "right" << std::endl;
      }
      else if (message->sender->getSprite().getGlobalBounds().top < sprite.getGlobalBounds().top) {
        msg->collide.direction = UP;
        std::cout << "up" << std::endl;
      }
      else if (message->sender->getSprite().getGlobalBounds().top + msg->sender->getSprite().getGlobalBounds().height > sprite.getGlobalBounds().top + sprite.getGlobalBounds().height) {
        msg->collide.direction = DOWN;
        std::cout << "down" << std::endl;
      }
      Game::getInstance().sendMessage(msg);
    }
    break;
  case ACTIVATE:
    if (message->activate.id == id)
      isOpen = !isOpen;
    break;
  default:
    break;
  }
}
