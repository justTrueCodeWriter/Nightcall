#include "../include/Tile.hpp"
#include "../include/ResourceManager.hpp"
#include "iostream"

UsualTile::UsualTile(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('='));
  sprite.scale(0.5, 0.5);
  sprite.setPosition(x_, y_);
  inMessage_ = new Message();
  outMessage_ = new Message();
}

UsualTile::~UsualTile() {
  delete inMessage_;
  delete outMessage_;
}

char UsualTile::getType() { return '='; }

void UsualTile::update(float time) {

  outMessage_->object_type = getType();
  outMessage_->action = COLLIDE;
  outMessage_->x = x_;
  outMessage_->y = y_;
}
