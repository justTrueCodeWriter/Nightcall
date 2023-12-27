#include "../include/Button.hpp"
#include "../include/ResourceManager.hpp"

Button::Button(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('b'));
}

void Button::update(float time) {
  if (message_ == "interact")
    sendMessage("activate");
}
