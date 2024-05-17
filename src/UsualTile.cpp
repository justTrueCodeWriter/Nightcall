#include "../include/UsualTile.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Game.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <iostream>

UsualTile::UsualTile(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('='));
  sprite.scale(0.5, 0.5);
  sprite.setPosition(x_, y_);
}

void UsualTile::sendMessage(Message* message) {
  if (message->sender == this) return;

}