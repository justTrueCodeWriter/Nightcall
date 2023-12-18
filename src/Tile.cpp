#include "../include/Tile.hpp"

Tile::Tile(float x, float y) {
  x_ = x; 
  y_ = y;
  texture.loadFromFile("media/img/usual_tile.png");
  sprite.setTexture(texture);
}

sf::Sprite Tile::getSprite(){ return sprite; };
