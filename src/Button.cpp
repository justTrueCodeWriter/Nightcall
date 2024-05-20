#include "../include/Button.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Game.hpp"
#include <iostream>

int Button::id_counter = 0;

Button::Button(float x, float y) {
  id = id_counter;
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('b'));
  sprite.scale(0.08, 0.08);
  sprite.setPosition(x_, y_);
  id_counter++;
}

void Button::update(float time) {
}

void Button::sendMessage(Message* message) {
    static sf::Clock cooldown_clock;
    if (message->sender == this) return;
    switch (message->action) {
      case INTERACT:
        if (message->sender->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()) &&
            cooldown_clock.getElapsedTime().asSeconds() > 1) {
          cooldown_clock.restart();
          Message* msg = new Message;
          msg->action = ACTIVATE;
          msg->sender = this;
          msg->activate.id = id;
          Game::getInstance().sendMessage(msg);
        }
        break;
      default:
        break;
    }
}
