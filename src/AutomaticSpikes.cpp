#include "../include/AutomaticSpikes.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Game.hpp"
#include "../include/Hero.hpp"
#include <SFML/System/Clock.hpp>

#include <codecvt>
#include <iostream>

int AutomaticSpikes::id_counter = 0;

AutomaticSpikes::AutomaticSpikes(float x, float y) {
  id = id_counter;

  x_ = x, y_ = y+10; 
  start_pos_x = x, start_pos_y = y+10;

  sprite.setTexture(*ResourceManager::getInstance().getTexture('^'));
  sprite.scale(0.65, 0.5);
  sprite.setPosition(x_, y_);
  id_counter++;
}

void AutomaticSpikes::update(float time) {
    if (isActive) {
      static sf::Clock activation_clock;
        if (!isAlreadyActivated) {
          sprite.move(0, -sprite.getGlobalBounds().height);
          isAlreadyActivated = true;
        }
        if (activation_clock.getElapsedTime().asSeconds() > 2) {
          activation_clock.restart();
          sprite.setPosition(start_pos_x, start_pos_y);
          isActive = false;
          isAlreadyActivated = false;
        }
    }
}

void AutomaticSpikes::sendMessage(Message* message) {

  if (message->sender == this) return;

  switch (message->action) {
    case ACTIVATE:
       if (message->activate.id == id)
        isActive = true;
    break;
    default:
      if (message->sender->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds())) {
        Message* msg = new Message;
        msg->action = ATTACK;
        msg->sender = this;
        Game::getInstance().sendMessage(msg);
      }
    break;
  }
}
