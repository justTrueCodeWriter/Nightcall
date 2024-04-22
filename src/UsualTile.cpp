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
      std::cout << "Correct MOVE" << std::endl;
      if (message->sender->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds())) { // TODO: fix collision problem
        Message* message = new Message;
        message->sender = this;
        message->action = COLLIDE;
        if (message->sender->getSprite().getGlobalBounds().left < sprite.getGlobalBounds().left)
          message->collide.direction = LEFT;
        else if (message->sender->getSprite().getGlobalBounds().left + message->sender->getSprite().getGlobalBounds().width > sprite.getGlobalBounds().left + sprite.getGlobalBounds().width)
          message->collide.direction = RIGHT;
        else if (message->sender->getSprite().getGlobalBounds().top < sprite.getGlobalBounds().top)
          message->collide.direction = UP;
        else if (message->sender->getSprite().getGlobalBounds().top + message->sender->getSprite().getGlobalBounds().height > sprite.getGlobalBounds().top + sprite.getGlobalBounds().height)
          message->collide.direction = DOWN;
        Game::getInstance().sendMessage(message);
        std::cout << "Correct collision" << std::endl;
      }
      break;
    default:
      break;
  }

}