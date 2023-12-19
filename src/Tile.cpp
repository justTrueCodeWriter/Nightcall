#include "../include/Tile.hpp"

Tile::Tile(float x, float y) {
  texture.loadFromFile("media/img/usual_tile.png");
  sprite.setTexture(texture);
  sprite.scale(0.2, 0.2);
  sprite.setPosition(x, y);
}

sf::Sprite Tile::getSprite(){ return sprite; };
