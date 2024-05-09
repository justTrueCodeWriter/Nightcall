#include "../include/UsualTile.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Game.hpp"
#include <iostream>

UsualTile::UsualTile(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('='));
  sprite.scale(0.5, 0.5);
  sprite.setPosition(x_, y_);
}

UsualTile::~UsualTile() {
}

void UsualTile::sendMessage(Message* message) {
  if (message->sender == this) return;

  switch (message->action) {
    case MOVE:
      if (message->sender->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds())) { // TODO: fix collision problem
        Message* msg = new Message;
        msg->sender = this;
        msg->action = COLLIDE;
        if (msg->sender->getSprite().getGlobalBounds().left < sprite.getGlobalBounds().left) {
          msg->collide.direction = LEFT;
          std::cout << "left" << std::endl;
        }
        else if (msg->sender->getSprite().getGlobalBounds().left + msg->sender->getSprite().getGlobalBounds().width > sprite.getGlobalBounds().left + sprite.getGlobalBounds().width) {
          msg->collide.direction = RIGHT;
          std::cout << "right" << std::endl;
        }
        else if (message->sender->getSprite().getGlobalBounds().top < sprite.getGlobalBounds().top)
          msg->collide.direction = UP;
        else if (msg->sender->getSprite().getGlobalBounds().top + msg->sender->getSprite().getGlobalBounds().height > sprite.getGlobalBounds().top + sprite.getGlobalBounds().height)
          msg->collide.direction = DOWN;
        Game::getInstance().sendMessage(msg);
      }
      break;
    default:
      break;
  }

}