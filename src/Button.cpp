#include "../include/Button.hpp"
#include "../include/ResourceManager.hpp"
#include <iostream>

Button::Button(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('b'));
  sprite.scale(0.08, 0.08);
  sprite.setPosition(x_, y_);
}

void Button::update(float time) {
  if (message_ == "interact") {
    sendMessage("activate");
    std::cout << message_ << std::endl;
  }
}

char Button::getType() { return 'b'; }