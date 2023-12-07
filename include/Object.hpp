#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SFML/Graphics.hpp>

class Object {
  public:
    virtual void load(float time){};
    virtual sf::Sprite getSprite(){ return sf::Sprite(); };
};
#endif
