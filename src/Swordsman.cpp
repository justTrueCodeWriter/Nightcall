#include "../include/Swordsman.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Hero.hpp"
#include "../include/Game.hpp"

Swordsman::Swordsman(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('S'));
  sprite.setTextureRect(sf::IntRect(19, 35, 35, 29));
  sprite.scale(2, 2);
  sprite.setPosition(x_, y_); 
}

Swordsman::~Swordsman() {
}

void Swordsman::update(float time) {
  const float defeat_distance = 30.0;
    move(time);
}

// char Swordsman::getType() { return 'S'; }

void Swordsman::move(float time) {
  float frame_life = 12;
  static float current_frame = 0;

  Message* message = new Message;
  message->action = ATTACK;
  message->sender = this;
  Game::getInstance().sendMessage(message);

  if (current_frame > frame_life) {
    current_frame = 0;
    direction_ = -direction_;
  }
  current_frame += 0.03*time;
  if (direction_ > 0)
    sprite.setTextureRect(sf::IntRect(19, 35, 35, 29));
  else if (direction_ < 0) {
    sprite.setTextureRect(sf::IntRect(54, 33, -35, 29)); 
  }

  x_+=direction_*speed*time;
  //std::cout << x_ << std::endl;

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
        break;
    default:
        break;
    }
}
