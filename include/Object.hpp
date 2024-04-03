#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SFML/Graphics.hpp>
#include "Message.hpp"

//TODO: fix object symlinks

class Object {
  public:
    virtual ~Object(){};

    float x_ = 0, y_ = 0;
    sf::Sprite sprite;

    virtual void sendMessage(Message* message);
    sf::Sprite getSprite(){ return sprite; };
    virtual void update(float time){};
};
#endif
