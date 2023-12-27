#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SFML/Graphics.hpp>

class Object {
  public:
    float x_ = 0, y_ = 0;
    std::string message_ = "";
    sf::Sprite sprite;

    void sendMessage(std::string message){ message_ = message; };
    std::string getMessage(){ return message_; };
    sf::Sprite getSprite(){ return sprite; };
    virtual void update(float time){};
    virtual char getType(){ return char(); };
};
#endif
