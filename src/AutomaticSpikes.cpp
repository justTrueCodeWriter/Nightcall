#include "../include/AutomaticSpikes.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Game.hpp"
#include "../include/Hero.hpp"
#include <SFML/System/Clock.hpp>

int AutomaticSpikes::id_counter = 0;

AutomaticSpikes::AutomaticSpikes(float x, float y) {
  id = id_counter;
  x_ = x, y_ = y+10; 
  sprite.setTexture(*ResourceManager::getInstance().getTexture('^'));
  sprite.scale(0.65, 0.5);
  sprite.setPosition(x_, y_);
  id_counter++;
}

void AutomaticSpikes::update(float time) {
    static sf::Clock activation_clock;
    if (isActive) {
        if (activation_clock.getElapsedTime().asSeconds() > 2) {
          activation_clock.restart();
          y_ += sprite.getGlobalBounds().height;
          sprite.setPosition(x_, y_);
          isActive = false;
          isAlreadyActivated = false;
        }
        if (!isAlreadyActivated) {
          y_ -= sprite.getGlobalBounds().height;
          sprite.setPosition(x_, y_);
          isAlreadyActivated = true;
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
    case MOVE:
      if (message->sender->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds())) {
        Message* msg = new Message;
        msg->action = ATTACK;
        msg->sender = this;
        Game::getInstance().sendMessage(msg);
      }
    break;
  default:
    break;
  }
}
