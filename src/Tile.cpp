#include "../include/Tile.hpp"
#include "../include/ResourceManager.hpp"
#include "iostream"

UsualTile::UsualTile(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('='));
  sprite.scale(0.5, 0.5);
  sprite.setPosition(x_, y_);
}

char UsualTile::getType() { return '='; }
