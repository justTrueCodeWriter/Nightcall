#include "../include/Door.hpp"
#include "../include/ResourceManager.hpp"
#include <math.h>

Door::Door(float x, float y) {
  x_ = x, y_ = y; 
  sprite.setTexture(*ResourceManager::getInstance().getTexture('d'));
  sprite.setTextureRect(sf::IntRect(7, 10, 53, 86));
  sprite.setPosition(x_, y_);
  inMessage_ = new Message();
  outMessage_ = new Message();
}

Door::~Door() {
  delete inMessage_;
  delete outMessage_;
}

void Door::update(float time) {

  if (fabs(inMessage_->sprite_rect.left - x_)<=64.0 && fabs(inMessage_->sprite_rect.top - y_)<=32.0 && inMessage_->object_type == 'b' && inMessage_->action == ACTIVATE) {
    isOpen = !isOpen;
    inMessage_->action = NONE;
  }

  if (isOpen) {
    sprite.setTextureRect(sf::IntRect(415, 106, 53, 86));
  }
  else if (!isOpen) {
    sprite.setTextureRect(sf::IntRect(7, 10, 53, 86));
  }
}

char Door::getType() { return 'd'; }
