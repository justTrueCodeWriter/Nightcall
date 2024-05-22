#include "../include/TriggerGates.hpp"
#include "../include/Game.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Hero.hpp"

int TriggerGates::id_counter = 0;

TriggerGates::TriggerGates(float x, float y) {
  id = id_counter;
  x_ = x, y_ = y;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('|'));
  sprite.setTextureRect(sf::IntRect(150,330, 24, 57));
  sprite.scale(1, 1.2);
  sprite.setPosition(x_, y_);
  id_counter++;
}

void TriggerGates::update(float time) {}

void TriggerGates::sendMessage(Message* message) {
    if (message->sender == this) return;
    
    switch (message->action) {
        case ATTACK:
            if (dynamic_cast<Hero *>(message->sender) != nullptr)
                return;
            break;
        case MOVE:
            if (message->sender->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()) &&
                dynamic_cast<Hero*>(message->sender) != nullptr) {
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
