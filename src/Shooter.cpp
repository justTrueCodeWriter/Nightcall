#include "../include/Shooter.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Hero.hpp"
#include "../include/Game.hpp"
#include "../include/Projectile.hpp"
#include <SFML/System/Clock.hpp>
#include <math.h>

Shooter::Shooter(float x, float y) {
  speed = 0.2;
  isColliding_ = true;
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('s'));
  sprite.setTextureRect(sf::IntRect(198, 164, 36, 27));
  sprite.scale(2.5, 2.5);
  sprite.setPosition(x_, y_); 
}

void Shooter::update(float time) {
    move(time);
}

void Shooter::move(float time) {
  float direction_time = 5;
  static float current_frame = 0;

  static sf::Clock direction_clock;

  if (direction_clock.getElapsedTime().asSeconds() > direction_time) {
    direction_clock.restart();
    direction_ = -direction_;
  }

  current_frame += 0.03*time;

  if (direction_ > 0)
    sprite.setTextureRect(sf::IntRect(178, 164, -36, 27));
  else if (direction_ < 0) {
    sprite.setTextureRect(sf::IntRect(198, 164, 36, 27)); 
  }

  x_+=direction_*speed*time;
  if (!isGround)
    y_+=0.5*time;

  sprite.setPosition(x_, y_);

}

void Shooter::sendMessage(Message* message) {
    if (message->sender == this) return;
    switch (message->action)
    {
    case ATTACK:
      if (message->sender->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds())) {
        if (dynamic_cast<Hero*> (message->sender) == nullptr)
            return;
        Message* msg = new Message;
        msg->action = DIED;
        msg->sender = this;
        msg->died.who = this;
        Game::getInstance().sendMessage(msg);
      }
        //check collision of attack rect and my rect

      break;

    case MOVE:
      if (dynamic_cast<Hero *>(message->sender) == nullptr) return;
      static sf::Clock cooldown_clock;
      if (fabs(message->sender->getSprite().getGlobalBounds().left-sprite.getGlobalBounds().left) <= 300 && 
          cooldown_clock.getElapsedTime().asSeconds() > 1) {
        if (message->sender->getSprite().getGlobalBounds().left - sprite.getGlobalBounds().left < 0) {
          Game::getInstance().pushObject(new Projectile(x_, y_, -1));
          cooldown_clock.restart();
        }
        else {
          Game::getInstance().pushObject(new Projectile(x_, y_, 1));
          cooldown_clock.restart();
        }
      }
        break;
    default:
        break;
    }
}
