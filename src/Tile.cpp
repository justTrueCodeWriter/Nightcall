#include "../include/Tile.hpp"

Tile::Tile(float x, float y, sf::Texture texture) {
  sprite.setTexture(texture);
  sprite.scale(0.5, 0.5);
  sprite.setPosition(x, y);
}

void Tile::sendMessage() {

}

void Tile::getMessage() {

}

sf::Sprite Tile::getSprite(){ return sprite; };
