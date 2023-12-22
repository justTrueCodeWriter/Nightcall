#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SFML/Graphics.hpp>

class Object {
  public:
    virtual void sendMessage(){};
    virtual void getMessage(){};
    virtual void update(float time){};
    virtual void setSprite(sf::Texture texture){}
    virtual sf::Sprite getSprite(){ return sf::Sprite(); };
};
#endif
