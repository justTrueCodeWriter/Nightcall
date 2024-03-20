#include "../include/Button.hpp"
#include "../include/ResourceManager.hpp"
#include <iostream>

Button::Button(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('b'));
  sprite.scale(0.08, 0.08);
  sprite.setPosition(x_, y_);
}
Button::~Button() {
}

//TODO: fix button activation
void Button::update(float time) {
  const float activation_distance = 30.0;
  float sprite_width = sprite.getLocalBounds().width;
  float sprite_height = sprite.getGlobalBounds().width;
  if ((inMessage_->sprite_rect.left+inMessage_->sprite_rect.width - x_<=activation_distance || inMessage_->sprite_rect.left-x_+sprite_width<=activation_distance) && 
    (inMessage_->sprite_rect.top+inMessage_->sprite_rect.height - y_<=activation_distance || inMessage_->sprite_rect.top-y_+sprite_height<=activation_distance) && 
    inMessage_->action == INTERACT) {

    outMessage_->object_type = getType();
    outMessage_->action = ACTIVATE;
    inMessage_->action = NONE;

  }
}

char Button::getType() { return 'b'; }
