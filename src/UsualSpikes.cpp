#include "../include/UsualSpikes.hpp"
#include "../include/ResourceManager.hpp"

UsualSpikes::UsualSpikes(float x, float y) {
  x_ = x, y_ = y; 
  sprite.setTexture(*ResourceManager::getInstance().getTexture('^'));
  sprite.scale(0.65, 0.5);
  sprite.setPosition(x_, y_);
  inMessage_ = new Message();
  outMessage_ = new Message();
}

UsualSpikes::~UsualSpikes() {
  delete inMessage_;
  delete outMessage_;
}

char UsualSpikes::getType() { return '^'; }

void UsualSpikes::update(float time) {
  outMessage_->object_type = getType();
  outMessage_->action = ATTACK;
  outMessage_->x = x_;
  outMessage_->y = y_;
  //outMessage_->sprite_rect = sprite.getGlobalBounds();
}
