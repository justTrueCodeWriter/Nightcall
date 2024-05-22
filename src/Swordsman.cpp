#include "../include/Swordsman.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Hero.hpp"
#include "../include/Game.hpp"
#include <SFML/System/Clock.hpp>

Swordsman::Swordsman(float x, float y) {
  speed = 0.5;
  isColliding_ = true;
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('S'));
  sprite.setTextureRect(sf::IntRect(19, 35, 35, 29));
  sprite.scale(2, 2);
  sprite.setPosition(x_, y_); 
}

void Swordsman::update(float time) {
    move(time);
}

// char Swordsman::getType() { return 'S'; }

void Swordsman::move(float time) {
  int direction_time = 5;

  Message* message = new Message;
  message->action = ATTACK;
  message->sender = this;
  Game::getInstance().sendMessage(message);

  if (direction_clock.getElapsedTime().asSeconds() > direction_time) {
    direction_clock.restart();
    direction_ = -direction_;
  }

  if (direction_ > 0)
    sprite.setTextureRect(sf::IntRect(19, 35, 35, 29));
  else if (direction_ < 0) {
    sprite.setTextureRect(sf::IntRect(54, 33, -35, 29)); 
  }

  x_+=direction_*speed*time;
/*   if (!isGround)
    y_+=0.5*time; */

  sprite.setPosition(x_, y_);

  // outMessage_->object_type = getType();
  // outMessage_->action = ATTACK;
  // outMessage_->sprite_rect = sprite.getGlobalBounds();
}

void Swordsman::sendMessage(Message* message) {
    if (message->sender == this) return;


    switch (message->action)
    {
    case ATTACK:
      if (message->sender->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds())) {
        if (dynamic_cast<Hero*>(message->sender) == nullptr) {
          return;
        }
        Message* msg = new Message;
        msg->action = DIED;
        msg->sender = this;
        msg->died.who = this;
        Game::getInstance().sendMessage(msg);

      }
        //check collision of attack rect and my rect

      break;
    case MOVE:
        break;
    default:
        break;
    }
}
