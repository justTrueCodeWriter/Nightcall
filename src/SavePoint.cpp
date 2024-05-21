#include "../include/SavePoint.hpp"
#include "../include/Game.hpp"
#include "../include/Hero.hpp"
#include "../include/ResourceManager.hpp"


SavePoint::SavePoint(float x, float y) {
  x_ = x, y_ = y+10;
  sprite.setTexture(*ResourceManager::getInstance().getTexture('~'));
  sprite.setTextureRect(sf::IntRect(1, 40, 16, 15));
  sprite.scale(1, 1.2);
  sprite.setPosition(x_, y_);
}

void SavePoint::update(float time) {}

void SavePoint::sendMessage(Message* message) {
    if (message->sender == this) return;
    switch (message->action) {
        default:
            if (message->sender->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()) &&
                dynamic_cast<Hero*>(message->sender) != nullptr) {
                Message* msg = new Message;
                msg->action = SAVE;
                msg->sender = this;
                Game::getInstance().sendMessage(msg);
            }
            break;
    }
}
