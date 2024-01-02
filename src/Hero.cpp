#include "../include/Hero.hpp"
#include "../include/ResourceManager.hpp"
#include <iostream>
#include <math.h>

Hero::Hero(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('H'));
  sprite.setPosition(x_, y_); 
  inMessage_ = new Message();
  outMessage_ = new Message();
}

void Hero::update(float time) { 
  static bool isAttack = false;
  if (fabs(inMessage_->x - x_)<=20.0 && fabs(inMessage_->y - y_)<=20.0 && inMessage_->action==ATTACK && inMessage_->object_type!=getType() && !isAttack) {
    printf("Hero killed\n");
    outMessage_->object_type = getType();
    outMessage_->action = DIED;
    outMessage_->x = x_;
    outMessage_->y = y_;
    return; 
  }
  move(time, isAttack); 
}

char Hero::getType() { return 'H'; }

void Hero::move(float time, bool& isAttack) {
  
    float speed = 0;
    static float current_frame = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
     outMessage_->object_type = getType();
     outMessage_->action = INTERACT;
     outMessage_->x = x_;
     outMessage_->y = y_;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
      side_ = -1;
      speed = run_speed_;

      current_frame += 0.01*time;
      if (current_frame > 10) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*46)+44, 292, -44, 44));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
      side_ = 1;
      speed = run_speed_;

      current_frame += 0.01*time;
      if (current_frame > 10) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*46), 292, 44, 44));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      isAttack = false;
      side_ = -1;
      speed = walk_speed_/2;
      
      current_frame += 0.008*time;
      if (current_frame > 8) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33)+33, 79, -33, 44));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      isAttack = false;
      side_ = 1;
      speed = walk_speed_/2;

      current_frame += 0.008*time;
      if (current_frame > 8) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33), 79, 33, 44));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || isAttack) {
      outMessage_->object_type = getType();
      outMessage_->action = ATTACK;
      outMessage_->x = x_;
      outMessage_->y = y_;
      speed = dash(time, isAttack);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
      if (inMessage_->action == COLLIDE)
        y_ -= 0.5 * time;
      else {
        y_ -= 0.9*time;
        current_frame += 0.01*time;
        if (current_frame > 4) current_frame = 0;
        if (side_ > 0)
          sprite.setTextureRect(sf::IntRect(39+(int(current_frame)*32), 650, 32, 44));
        else if  (side_ < 0)
          sprite.setTextureRect(sf::IntRect(39+(int(current_frame)*32)+32, 650, -32, 44));
      }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      y_ += 0.9*time;
    }
    else {
      current_frame += 0.01*time;
      if (inMessage_->action == COLLIDE) {
        if (current_frame > 12) current_frame = 0;
        if (side_ > 0)
          sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*36), 244, 36, 44));
        else if  (side_ < 0)
          sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*36)+36, 244, -36, 44));
      }
      else {
        if (current_frame > 4) current_frame = 0;
        if (side_ > 0) {
          sprite.setTextureRect(sf::IntRect(39+(int(current_frame)*32), 650, 32, 44));
        }
        else if  (side_ < 0) {
          sprite.setTextureRect(sf::IntRect(39+(int(current_frame)*32)+32, 650, -32, 44));
        }
      }
    }

    x_ += side_*speed*time;
    if (inMessage_->action == COLLIDE && fabs(inMessage_->y-y_)<=64.0 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      y_ += 0.9*time;
    sprite.setPosition(x_, y_); 
}

float Hero::dash(float time, bool &isAttack) {
  static float current_frame = 0;  
  isAttack = true;

  if (current_frame > 6) {
    current_frame = 0;
    isAttack = false;
  }
  current_frame += 0.03*time;
  if (side_ > 0)
    sprite.setTextureRect(sf::IntRect(33+(int(current_frame)*58), 768, 58, 44));
  else if (side_ < 0)
    sprite.setTextureRect(sf::IntRect(33+(int(current_frame)*58)+58, 768, -58, 44));
  return run_speed_*3;
}
