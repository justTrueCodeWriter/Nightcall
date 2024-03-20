#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SFML/Graphics.hpp>
#include "Message.hpp"

class Object {
  public:
    virtual ~Object(){};

    float x_ = 0, y_ = 0;
    sf::Sprite sprite;

    virtual void sendMessage(Message* msg);
    sf::Sprite getSprite(){ return sprite; };
    virtual void update(float time){};
    virtual char getType(){ return char(); };
};
#endif
