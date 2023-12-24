#include "../include/Tile.hpp"
#include "iostream"

Tile::Tile(float x, float y) {
  x_ = x, y_ = y;
}

void Tile::setSprite(sf::Texture texture) {
  sprite.setTexture(texture);
  sprite.scale(0.5, 0.5);
  sprite.setPosition(x_, y_);
}

char Tile::getType() { return '='; }
