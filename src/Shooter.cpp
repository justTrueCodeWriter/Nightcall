#include "../include/Shooter.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Hero.hpp"
#include "../include/Game.hpp"
#include "../include/Projectile.hpp"
#include <math.h>

Shooter::Shooter(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('s'));
  sprite.setTextureRect(sf::IntRect(198, 164, 36, 27));
  sprite.scale(2.5, 2.5);
  sprite.setPosition(x_, y_); 
}

void Shooter::update(float time) {
  const float defeat_distance = 30.0;
    move(time);
}

void Shooter::move(float time) {
  float frame_life = 12;
  static float current_frame = 0;

/*   Message* message = new Message;
  message->action = ATTACK;
  message->sender = this;
  Game::getInstance().sendMessage(message); */

  if (current_frame > frame_life) {
    current_frame = 0;
    direction_ = -direction_;
  }
  current_frame += 0.03*time;
  if (direction_ > 0)
    sprite.setTextureRect(sf::IntRect(178, 164, -36, 27));
  else if (direction_ < 0) {
    sprite.setTextureRect(sf::IntRect(198, 164, 36, 27)); 
  }

  x_+=direction_*speed*time;

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
      if (dynamic_cast<Hero *>(message->sender) != nullptr &&
          fabs(message->sender->getSprite().getGlobalBounds().left +
               message->sender->getSprite().getGlobalBounds().width -
               sprite.getGlobalBounds().left) <= trigger_range &&
          !isBulletPulled) {
        Game::getInstance().push_object(new Projectile(x_, y_, -1));
        isBulletPulled = true;
      } else if (dynamic_cast<Hero *>(message->sender) != nullptr &&
                 fabs(message->sender->getSprite().getGlobalBounds().left -
                      sprite.getGlobalBounds().left +
                      sprite.getGlobalBounds().width) <= trigger_range &&
                 !isBulletPulled) {
        Game::getInstance().push_object(new Projectile(x_, y_, 1));
        isBulletPulled = true;
      }
        break;
    default:
        break;
    }
}
