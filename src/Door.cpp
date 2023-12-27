#include "../include/Door.hpp"
#include "../include/ResourceManager.hpp"

Door::Door(float x, float y) {
  x_ = x, y_ = y; 
  sprite.setTexture(*ResourceManager::getInstance().getTexture('d'));
}
