#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SFML/Graphics.hpp>
#include "Message.hpp"

class Object {
  public:
    float x_ = 0, y_ = 0;
    Message message_;
    sf::Sprite sprite;

    void getMessage(Message message){ message_ = message; };
    Message sendMessage(){ return message_; };
    sf::Sprite getSprite(){ return sprite; };
    virtual void update(float time){};
    virtual char getType(){ return char(); };
};
#endif
