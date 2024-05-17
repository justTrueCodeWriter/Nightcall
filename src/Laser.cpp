#include "../include/Laser.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Game.hpp"
#include "../include/Hero.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <cstddef>

Laser::Laser(float x, float y) {
  x_ = x, y_ = y; 
  sprite.setTexture(*ResourceManager::getInstance().getTexture('|'));
  sprite.setTextureRect(sf::IntRect(232, 327, 4, 57));
  sprite.scale(1, 1.2);
  sprite.setPosition(x_, y_);
}

void Laser::update(float time) {

}

void Laser::sendMessage(Message* message) {

  if (message->sender == this) return;

  switch (message->action) {
  case ATTACK:
    if (dynamic_cast<Hero *>(message->sender) != nullptr)
      return;
    break;
  default:
    Message *msg = new Message;
    msg->action = ATTACK;
    msg->sender = this;
    Game::getInstance().sendMessage(msg);
    break;
  }
}
