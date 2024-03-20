#include "../include/UsualTile.hpp"
#include "../include/ResourceManager.hpp"
#include "iostream"

UsualTile::UsualTile(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('='));
  sprite.scale(0.5, 0.5);
  sprite.setPosition(x_, y_);
}

UsualTile::~UsualTile() {
}

char UsualTile::getType() { return '='; }

void UsualTile::update(float time) {
  outMessage_->object_type = getType();
  outMessage_->action = COLLIDE;
  outMessage_->sprite_rect = sprite.getGlobalBounds();
}
