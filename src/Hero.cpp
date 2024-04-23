#include "../include/Hero.hpp"
#include "../include/Game.hpp"
#include "../include/ResourceManager.hpp"
#include <unistd.h>
#include <iostream>

Hero::Hero(float x, float y) {
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('H'));
  sprite.setPosition(x_, y_); 
  collide_rect = {x_, y_+sprite.getGlobalBounds().height, 10, 10};

}

Hero::~Hero() {
}

void Hero::update(float time) { 
  float sprite_x_center = x_+sprite.getGlobalBounds().width/2;
  float sprite_y_center = y_+sprite.getGlobalBounds().height/2;

  move(time); 
}

void Hero::move(float time) {
  
    float speed = 0;
    static float current_frame = 0;

// ------------ INTERACTION WITH OBJECTS ON MAP -----------
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
     Message *message = new Message;
     message->action = INTERACT;
     message->sender = this;
     Game::getInstance().sendMessage(message);
     usleep(60*1000);
    }
// ------------ RUN LEFT -----------
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
      side_ = -1;
      speed = run_speed_;

      current_frame += 0.01*time;
      if (current_frame > 10) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*46)+44, 292, -44, 44));
    }
// ------------ RUN RIGHT -----------
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
      side_ = 1;
      speed = run_speed_;

      current_frame += 0.01*time;
      if (current_frame > 10) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*46), 292, 44, 44));
    }
// ------------ GO LEFT -----------
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      isAttack = false;
      side_ = -1;
      speed = walk_speed_/2.0;
      
      current_frame += 0.008*time;
      if (current_frame > 8) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33)+33, 79, -33, 44));
    }
// ------------ GO RIGHT -----------
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      isAttack = false;
      side_ = 1;
      speed = walk_speed_/2.0;

      current_frame += 0.008*time;
      if (current_frame > 8) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33), 79, 33, 44));
    }
// ------------ ATTACK -----------
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || isAttack) {
      Message* message = new Message;
      message->action = ATTACK;
      message->sender = this;
      Game::getInstance().sendMessage(message);
      speed = dash(time);
    }
// ------------ JUMP -----------
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
      isGround = false;
        y_ -= 0.9*time;
        current_frame += 0.01*time;
        if (current_frame > 4) current_frame = 0;
        if (side_ > 0)
          sprite.setTextureRect(sf::IntRect(39+(int(current_frame)*32), 650, 32, 44));
        else if  (side_ < 0)
          sprite.setTextureRect(sf::IntRect(39+(int(current_frame)*32)+32, 650, -32, 44));
    }
// ------------ FLY DOWN(TEMPORERILY) -----------
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      y_ += 0.9*time;
    }
// ------------ STAY STILL -----------
    else {
      current_frame += 0.01*time;
      // if (inMessage_->action == COLLIDE) {
      //   if (current_frame > 12) current_frame = 0;
      //   if (side_ > 0)
      //     sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*36), 244, 36, 44));
      //   else if  (side_ < 0)
      //     sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*36)+36, 244, -36, 44));
      // }
      // else {
        if (current_frame > 4) current_frame = 0;
        if (side_ > 0) {
          sprite.setTextureRect(sf::IntRect(39+(int(current_frame)*32), 650, 32, 44));
        }
        else if  (side_ < 0) {
          sprite.setTextureRect(sf::IntRect(39+(int(current_frame)*32)+32, 650, -32, 44));
        }
    }

    x_ += side_*speed*time;
    //if (!isGround)
      //y_ += 0.9*time;
    if (speed != 0) {
      Message *message = new Message;
      message->action = MOVE;
      message->sender = this;
      Game::getInstance().sendMessage(message);
      std::cout << x_ << "MOVE" << y_ << std::endl;
    }
    sprite.setPosition(x_, y_); 
}

float Hero::dash(float time) {
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

void Hero::sendMessage(Message* message) {
  if (message->sender == this) return;

  switch (message->action) {
    case ATTACK:
      if (message->sender->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()) &&
          !isAttack) {
        Message* msg = new Message;
        msg->action = DIED;
        msg->sender = this;
        msg->died.who = this;
        Game::getInstance().sendMessage(msg);
      }
      break;
    case COLLIDE:
      if (message->collide.direction == UP)
        isGround = true;
    default:
      break;
  }
}
