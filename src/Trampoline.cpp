#include "../include/Trampoline.hpp"
#include "../include/ResourceManager.hpp"

Trampoline::Trampoline(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('~'));
  sprite.setTextureRect(sf::IntRect(64, 40, 32, 16));
  sprite.scale(1.5,1.5);
  sprite.setPosition(x_+5, y_+40); 
}

void Trampoline::update(float time) {

}

void Trampoline::sendMessage(Message* message) {

}