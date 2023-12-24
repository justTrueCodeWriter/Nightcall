#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SFML/Graphics.hpp>

class Object {
  public:
    std::string message_ = "";
    sf::Sprite sprite;

    void sendMessage(std::string message){ message_ = message; };
    std::string getMessage(){ return message_; };
    sf::Sprite getSprite(){ return sprite; };
    virtual void update(float time){};
    virtual void setSprite(sf::Texture texture){}
    virtual char getType(){ return char(); };
};
#endif
