#include "../include/Swordsman.hpp"
#include "../include/ResourceManager.hpp"
#include <iostream>
#include <math.h>

Swordsman::Swordsman(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('S'));
  sprite.setTextureRect(sf::IntRect(19, 35, 35, 29));
  sprite.scale(2, 2);
  sprite.setPosition(x_, y_); 
  inMessage_ = new Message();
  outMessage_ = new Message();
}

void Swordsman::update(float time) {
  if (fabs(inMessage_->x - x_)<=30.0 && fabs(inMessage_->y - y_)<=30.0 && inMessage_->object_type == 'H' && inMessage_->action == ATTACK) {
    printf("Swordsman killed\n");
    outMessage_->object_type = getType();
    outMessage_->action = DIED;
    outMessage_->x = x_;
    outMessage_->y = y_;
    return;
  }
  move(time);
}

char Swordsman::getType() { return 'S'; }

void Swordsman::move(float time) {
  if (side_ > 0)
    sprite.setTextureRect(sf::IntRect(19, 35, 35, 29));
  else if (side_ < 0)
    sprite.setTextureRect(sf::IntRect(19, 35, -35, 29)); 
  outMessage_->object_type = getType();
  outMessage_->action = ATTACK;
  outMessage_->x = x_;
  outMessage_->y = y_;
  sprite.setPosition({x_, y_});
}
