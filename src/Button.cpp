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
}

// char Button::getType() { return 'b'; }

void Button::sendMessage(Message* message) {

    if (message->sender == this) return;
    switch (message->action) {
      case ACTIVATE:
        
        break;
    }
}
