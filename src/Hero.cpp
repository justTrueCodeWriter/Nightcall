#include "../include/Hero.hpp"
#include "../include/Game.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Trampoline.hpp"
#include <unistd.h>

Hero::Hero(float x, float y) {
  isColliding_ = true;
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('H'));
  sprite.setPosition(x_, y_); 
  //collide_rect = {x_, y_+sprite.getGlobalBounds().height, 10, 10};

}

void Hero::update(float time) { 
/*   float sprite_x_center = x_+sprite.getGlobalBounds().width/2;
  float sprite_y_center = y_+sprite.getGlobalBounds().height/2; */

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
    }
// ------------ RUN LEFT -----------
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && 
            sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) &&
            collide_side!=RIGHT) {
      isAttack = false;
      isJump = false;

      direction_ = -1;
      speed = run_speed_;


      current_frame += 0.01*time;
      if (current_frame > 10) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*46)+44, 292, -44, 44));

      collide_side = NONE;
    }
// ------------ RUN RIGHT -----------
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && 
            sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) &&
            collide_side!=LEFT) {
      isAttack = false;
      isJump = false;

      direction_ = 1;
      speed = run_speed_;

      current_frame += 0.01*time;
      if (current_frame > 10) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*46), 292, 44, 44));

      collide_side = NONE;
    }
// ------------ GO LEFT -----------
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && collide_side!=RIGHT) {
      isAttack = false;
      isJump = false;
      direction_ = -1;
      speed = walk_speed_/2.0;
      
      current_frame += 0.008*time;
      if (current_frame > 8) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33)+33, 79, -33, 44));

      collide_side = NONE;
    }
// ------------ GO RIGHT -----------
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && collide_side!=LEFT) {
      isAttack = false;
      isJump = false;
      direction_ = 1;
      speed = walk_speed_/2.0;

      current_frame += 0.008*time;
      if (current_frame > 8) current_frame = 0;
      sprite.setTextureRect(sf::IntRect(44+(int(current_frame)*33), 79, 33, 44));

      collide_side = NONE;
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
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || isJump){
      isAttack = false;

      static sf::Clock jump_cooldown;
      if (jump_cooldown.getElapsedTime().asSeconds() > 1)

      jump(time);
    }
// ------------ FLY DOWN(TEMPORERILY) -----------
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      y_ += 0.9*time;
    }
// ------------ STAY STILL -----------
    else {
      current_frame += 0.01*time;
        if (current_frame > 4) current_frame = 0;
        if (direction_ > 0) {
          sprite.setTextureRect(sf::IntRect(39+(int(current_frame)*32), 650, 32, 44));
        }
        else if  (direction_ < 0) {
          sprite.setTextureRect(sf::IntRect(39+(int(current_frame)*32)+32, 650, -32, 44));
        }
    }

    x_ += direction_*speed*time;
    if (!isJump)
      y_ += 0.5*time;

    if (speed != 0) {
      Message *message = new Message;
      message->action = MOVE;
      message->sender = this;
      Game::getInstance().sendMessage(message);
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
  if (direction_ > 0)
    sprite.setTextureRect(sf::IntRect(33+(int(current_frame)*58), 768, 58, 44));
  else if (direction_ < 0)
    sprite.setTextureRect(sf::IntRect(33+(int(current_frame)*58)+58, 768, -58, 44));
  return run_speed_*3;
}

void Hero::jump(float time) {
  static float current_frame = 0;

  isJump = true;

  static sf::Clock jump_clock;
  if (jump_clock.getElapsedTime().asSeconds() > 0.1) {
    jump_clock.restart();
    isJump = false;
  } 

  y_ -= 0.9 * time;
  current_frame += 0.01 * time;
  if (current_frame > 4)
    current_frame = 0;
  if (direction_ > 0)
    sprite.setTextureRect(
        sf::IntRect(39 + (int(current_frame) * 32), 650, 32, 44));
  else if (direction_ < 0)
    sprite.setTextureRect(
        sf::IntRect(39 + (int(current_frame) * 32) + 32, 650, -32, 44));
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
      collide_side = message->collide.direction;
    case INTERACT:
      if (dynamic_cast<Trampoline*>(message->sender) == nullptr) return;

      if (message->sender->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds())) {
        //for (int i = 0; i < 3; i++)
          //jump();
      }
    default:
      break;
  }
}
