#include "../include/Projectile.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Game.hpp"
#include <SFML/System/Clock.hpp>
#include <iostream>


Projectile::Projectile(float x, float y, short direction){
  x_ = x, y_ = y, direction_ = direction;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('s'));
  sprite.setTextureRect(sf::IntRect(354, 289, 13, 13));
  sprite.scale(2, 2);
  sprite.setPosition(x_, y_); 
}

void Projectile::update(float time){
  static sf::Clock life_clock;

  if (life_clock.getElapsedTime().asSeconds() > 1) {
    life_clock.restart();
    Message *message = new Message;
    message->action = DIED;
    message->sender = this;
    message->died.who = this;
    Game::getInstance().sendMessage(message);
  }

  move(time);
  Message* message = new Message;
  message->action = ATTACK;
  message->sender = this;
  Game::getInstance().sendMessage(message);
}

void Projectile::move(float time){
  x_+=direction_*speed*time;
  sprite.setPosition(x_, y_);

}

void Projectile::sendMessage(Message* message){

}