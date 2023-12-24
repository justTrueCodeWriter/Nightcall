#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SFML/Graphics.hpp>

class Object {
  public:
    virtual void sendMessage(std::string message){};
    virtual std::string getMessage(){ return std::string(); };
    virtual void update(float time){};
    virtual void setSprite(sf::Texture texture){}
    virtual sf::Sprite getSprite(){ return sf::Sprite(); };
};
#endif
