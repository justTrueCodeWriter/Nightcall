#include "../include/Button.hpp"
#include "../include/ResourceManager.hpp"
#include <iostream>
#include <math.h>

Button::Button(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('b'));
  sprite.scale(0.08, 0.08);
  sprite.setPosition(x_, y_);
  inMessage_ = new Message();
  outMessage_ = new Message();
}

void Button::update(float time) {
  if (fabs(inMessage_->x - x_)<=30.0 && fabs(inMessage_->y - y_)<=30.0 && inMessage_->action == INTERACT) {
    outMessage_->object_type = getType();
    outMessage_->action = ACTIVATE;
    outMessage_->x = x_;
    outMessage_->y = y_;
  }
}

char Button::getType() { return 'b'; }
