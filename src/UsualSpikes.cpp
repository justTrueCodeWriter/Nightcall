#include "../include/UsualSpikes.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Game.hpp"

UsualSpikes::UsualSpikes(float x, float y) {
  x_ = x, y_ = y; 
  sprite.setTexture(*ResourceManager::getInstance().getTexture('^'));
  sprite.scale(0.65, 0.5);
  sprite.setPosition(x_, y_);
}

void UsualSpikes::update(float time) {
  Message* message = new Message;
  message->action = ATTACK;
  message->sender = this;
  Game::getInstance().sendMessage(message);
}

void UsualSpikes::sendMessage(Message* message) {

}
