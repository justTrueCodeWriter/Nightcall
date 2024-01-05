#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SFML/Graphics.hpp>
#include "Message.hpp"

class Object {
  public:
    virtual ~Object(){};

    float x_ = 0, y_ = 0;
    Message *inMessage_;
    Message *outMessage_;
    sf::Sprite sprite;

    void getMessage(Message *message){ inMessage_ = message; };
    Message *sendMessage(){ return outMessage_; };
    sf::Sprite getSprite(){ return sprite; };
    virtual void update(float time){};
    virtual char getType(){ return char(); };
};
#endif
