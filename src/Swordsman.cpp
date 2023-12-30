#include "../include/Swordsman.hpp"
#include "../include/ResourceManager.hpp"
#include <iostream>

Swordsman::Swordsman(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('S'));
  sprite.scale(2, 2);
}

void Swordsman::update(float time) {
  if (message_.object_type == 'H' && message_.action == ATTACK) {
    std::cout << "killed by hero" << std::endl;
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
  sprite.setPosition({x_, y_});
}
