#include "../include/Swordsman.hpp"
#include "../include/ResourceManager.hpp"
#include <iostream>
#include <math.h>

Swordsman::Swordsman(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('S'));
  sprite.setTextureRect(sf::IntRect(19, 35, 35, 29));
  sprite.scale(2, 2);
  sprite.setPosition(x_, y_); 
}

Swordsman::~Swordsman() {
  std::cout << "Deleted" << std::endl;
}

void Swordsman::update(float time) {
  const float defeat_distance = 30.0;
  if (fabs(inMessage_->sprite_rect.left - x_)<=defeat_distance && fabs(inMessage_->sprite_rect.top - y_)<=defeat_distance && inMessage_->object_type == 'H' && inMessage_->action == ATTACK) {
    printf("Swordsman killed\n");
    outMessage_->object_type = getType();
    outMessage_->action = DIED;
    outMessage_->sprite_rect = sprite.getGlobalBounds();
    return;
  }
  if (outMessage_->action!=DIED)
    move(time);
}

char Swordsman::getType() { return 'S'; }

void Swordsman::move(float time) {
  float frame_life = 12;
  static float current_frame = 0;
 
  if (current_frame > frame_life) {
    current_frame = 0;
    side_ = -side_;
  }
  current_frame += 0.03*time;
  if (side_ > 0)
    sprite.setTextureRect(sf::IntRect(19, 35, 35, 29));
  else if (side_ < 0) {
    sprite.setTextureRect(sf::IntRect(19, 35, -35, 29)); 
  }

  x_+=side_*speed*time;
  //std::cout << x_ << std::endl;

  sprite.setPosition(x_, y_);

  outMessage_->object_type = getType();
  outMessage_->action = ATTACK;
  outMessage_->sprite_rect = sprite.getGlobalBounds();
}

void Swordsman::sendMessage(Message* msg) {
    if (msg->sender == this) return;
    switch (msg->action)
    {
    case ATTACK:
        if (dynamic_cast<Hero*> (msg->sender) == nullptr)
            return;

        //check collision of attack rect and my rect

        break;

    case MOVE:

        break;
    }
}
